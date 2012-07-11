/*
 * server_session.hpp
 *
 *  Created on: May 25, 2012
 *      Author: xingzhi
 */

#ifndef SERVER_SESSION_HPP_
#define SERVER_SESSION_HPP_

#include <participant.hpp>

namespace miu {

using boost::asio::ip::tcp;

class server_session : public participant {
private:
	typedef participant super;

public:
	boost::shared_ptr<session> counter_party_session;

public:
	server_session(boost::asio::io_service& io)
	: super(io) {
	}

	void connectTo(std::string& host, std::string& port) {
		std::cout << "connecting to " << host << ":" << port << std::endl;

		this->disconnect();

		tcp::resolver resolver(this->socket().get_io_service());
		tcp::resolver::query query(host, port);
		tcp::resolver::iterator iterator = resolver.resolve(query);

		this->socket().async_connect(*iterator,
				boost::bind(
						&server_session::handle_connect,
						boost::static_pointer_cast<server_session, session> (shared_from_this()),
						boost::asio::placeholders::error)
		);
	}

	void handle_connect(const boost::system::error_code& error) {
		std::cout << "server session handling connect \n" << std::endl;
		super::onConnect();
	}
};

}	// namespace miu

#endif /* SERVER_SESSION_HPP_ */
