/*
 * proxy_server.hpp
 *
 *  Created on: May 26, 2012
 *      Author: xingzhi
 */

#ifndef PROXY_SERVER_HPP_
#define PROXY_SERVER_HPP_

#include <cstdio>
#include <string>
#include <sstream>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/thread.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/unordered_map.hpp>
#include <boost/lexical_cast.hpp>
#include <session.hpp>
#include <session_manager.hpp>

const unsigned int maximum_concurrent_sessions_count = 100;

namespace miu {

using boost::asio::ip::tcp;

class proxy_server : public session_manager_delegate, public boost::enable_shared_from_this<proxy_server> {
private:
	typedef boost::shared_ptr<client_session> client_session_ptr;
	typedef boost::shared_ptr<session_manager> manager_ptr;

private:
	boost::asio::io_service	io_;

	boost::thread thread_;

	tcp::acceptor acceptor_;

	boost::unordered_map<std::string, manager_ptr> active_session_managers_;
	boost::unordered_map<std::string, manager_ptr> paused_session_managers_;

private:
	void start_accept() {
		client_session_ptr new_session(new client_session(io_));
		acceptor_.async_accept(new_session->socket(),
				boost::bind(&proxy_server::onAccept, shared_from_this(), new_session,
						boost::asio::placeholders::error));
	}

	void onAccept(client_session_ptr session, const boost::system::error_code& error) {
		if (!error) {
			printf("A new session joined, %lu sessions in total.\n", 1+active_session_managers_.size());

			if (can_start_new_session(session)) {
				session->set_handshake_received_callback(
						boost::bind(&proxy_server::client_session_handshake_received, this, _1, _2)
				);
				session->onConnect();
			}

			start_accept();
		}
		else {
			printf("error in creating listener\n");
			std::abort();
		}
	}

	//////////////////////////////////////////////////////////////////////////////////
	//																				//
	//	two opportunities to reject client sessions									//
	//	1. when a client session connected - can_start_new session					//
	//	2. when handshake done with identifier received - is_valid_client_session	//
	//																				//
	//////////////////////////////////////////////////////////////////////////////////

	bool can_start_new_session(client_session_ptr& session) {
		//
		// can block sessions by examining session's socket's remote_endpoint;
		//
		bool ip_blocked = false;
		if (ip_blocked) {
			session->handshake_error("your ip is not in the approved list");
			return false;
		}

		//
		// or impose a limit of concurrent_sessions cout;
		//
		bool room_available =  (active_session_managers_.size() < maximum_concurrent_sessions_count);
		if (!room_available) {
			session->handshake_error("maximum allowed concurrent sessions limit reached");
			return false;
		}

		return true;
	}

	bool is_valid_client_session(const client_session_ptr& client, handshake& handshake_message) {
	    // filter forwarding host
	    /*
	    if (handshake_message.host.compare("mybbshost.com") != 0) {
		client->handshake_error("only proxy to mybbshost.com is allowed.");
		return false;
	    }
	     */
	    // filter forwarding port
	    // CAUTION: filtering port is very important - otherwise it may create a big hole on your firewall
	     /*	
	    if (handshake_message.port != 23) {
		client->handshake_error("only proxy to port 23 is allowed.");
		return false;
	    }
	    */
	    // filter others like imcompatible hash / hostile uuid etc...
	    /*
	    if (is_bad_consumer(handshake_message.uuid())) {
		client->handshake_error("You are not welcomed! please don't try again");
		return false;
	    }

	    if (!is_hash_matched(handshake_message)) {
		client->handshake_error("You are not a registered service user...");
		return false;
	    }
	    */
	    return true;
	}

public:
	proxy_server (int listener_port)
	: acceptor_(io_, tcp::endpoint(tcp::v4(), listener_port)) {
	}

	void run() {
		start_accept();
		printf("Proxy server started on listener port %d\n", acceptor_.local_endpoint().port());

		thread_ = boost::thread(boost::bind(&boost::asio::io_service::run, &io_));
	}

	void shutdown() {
		io_.stop();
		thread_.interrupt();
		thread_.join();
	}

	//////////////////////////////////////////////////////////////////////////
	//																		//
	// client-session-identifier-received callback							//
	// When a client session connected, it will first send in an identifier	//
	// We use that identifier to find out if a corresponding sever session	//
	// was already set up.													//
	//																		//
	//////////////////////////////////////////////////////////////////////////
	std::string identfier_from_handshake(handshake& handshake_message) {
		std::stringstream s;
		s << handshake_message.user() << "@" << handshake_message.host() << ":" << handshake_message.port();
		return s.str();
	}

	void client_session_handshake_received (const boost::shared_ptr<client_session>& client, handshake& handshake_message) {
		printf("session handshake message: %s\n", handshake_message.DebugString().c_str());

		// an opportunity to reject connection given the handshake.
		if (!is_valid_client_session(client, handshake_message)) return;

		participant::this_ptr_type client_ptr = boost::static_pointer_cast<participant, client_session> (client);

		const std::string identifier = identfier_from_handshake(handshake_message);

		if (active_session_managers_.count(identifier) > 0) { // corresponding server session already established and active
			client->handshake_error("An proxy pair is already existed. Can not proceed");
			return;
		}
		else if (paused_session_managers_.count(identifier) > 0) { // corresponding server session already established and inactive
			manager_ptr& manager = paused_session_managers_[identifier];
			manager->set_client_session(client_ptr);

			active_session_managers_[identifier] = manager;
			paused_session_managers_.erase(identifier);
		}
		else { // new connection
			manager_ptr manager = manager_ptr(new session_manager(identifier, handshake_message.cookie(), io_, &(*this)));
			manager->set_client_session(client_ptr);
			active_session_managers_[identifier] = manager;
		}
	}

	//////////////////////////////
	//							//
	// proxy session handler	//
	//							//
	//////////////////////////////
	void proxy_session_finished(session_manager * manager) {
		const std::string& id(manager->identifier());
		active_session_managers_.erase(id);
		paused_session_managers_.erase(id);
		std::cout << "A proxy session finished. Cleaning up." << std::endl;
	}

	void proxy_session_paused(session_manager * manager) {
		const std::string& id(manager->identifier());
		if (active_session_managers_.count(id) > 0) {
			paused_session_managers_[id] = active_session_managers_[id];
			active_session_managers_.erase(id);
		}
		std::cout << "A proxy session paused." << std::endl;
	}
};

}	// namespace miu

#endif /* PROXY_SERVER_HPP_ */
