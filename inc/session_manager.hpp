/*
 * session_manager.hpp
 *
 *  Created on: May 26, 2012
 *      Author: xingzhi
 */

#ifndef SESSION_MANAGER_HPP_
#define SESSION_MANAGER_HPP_

#include<client_session.hpp>
#include<server_session.hpp>

#include <boost/asio.hpp>
#include <boost/shared_ptr.hpp>
#include <client_session.hpp>
#include <server_session.hpp>

namespace miu {

class session_manager;

class session_manager_delegate {
public:
	virtual ~session_manager_delegate() { };
	virtual void proxy_session_finished(session_manager * manager) = 0;
	virtual void proxy_session_paused(session_manager * manager) = 0;
};

class session_manager : public session_event_handler {
private:
	typedef boost::shared_ptr<participant> session_ptr_type;
private:
	session_ptr_type pClient_;
	session_ptr_type pServer_;

	std::string identifier_;
	std::string pass_;
	boost::asio::io_service& io_;
	session_manager_delegate& delegate_;
public:
	session_manager(const std::string& identifier, const std::string& pass, boost::asio::io_service& io, session_manager_delegate * delegate)
		: identifier_(identifier), pass_(pass), io_(io), delegate_(*delegate) {
	}

	void set_client_session(session_ptr_type& client) {
		pClient_ = client;
		pClient_->handler = this;

		if (!pServer_) {
			pServer_ = session_ptr_type(new server_session(io_));
			pServer_->handler = this;
			std::string host("ptt.cc");
			std::string port("23");
			(boost::static_pointer_cast<server_session>(pServer_))->connectTo(host, port);

			pClient_->counter_party_session = pServer_;
			pServer_->counter_party_session = pClient_;
		}
		else {
			pClient_->counter_party_session = pServer_;
			pServer_->counter_party_session = pClient_;

			pClient_->async_read();
		}
	}

	std::string& identifier () {
		return identifier_;
	}

	std::string& pass() {
		return pass_;
	}
	//////////////////////////////////
	//	session event handler
	//////////////////////////////////

	virtual void on_session_connected(participant * participant) {
		if (participant == &(*pServer_)) {
			pClient_->async_read();
		}
	}

	virtual void on_session_ended(participant * participant) {
		if (participant == &(*pServer_)) {
			pClient_->disconnect();
			delegate_.proxy_session_finished(this);
		}
		else if (participant == &(*pClient_)) {
			pClient_.reset();
		}
	}

	virtual void on_session_error(participant * participant) {
		if (participant == &(*pServer_)) {
			pClient_->disconnect();
			delegate_.proxy_session_finished(this);
		}
		else if (participant == &(*pClient_)) {
			pClient_.reset();
		}
	}

};

} // namespace miu

#endif /* SESSION_MANAGER_HPP_ */
