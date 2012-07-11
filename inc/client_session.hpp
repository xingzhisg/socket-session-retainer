/*
 * client_session.hpp
 *
 *  Created on: May 25, 2012
 *      Author: xingzhi
 */

#ifndef CLIENT_SESSION_HPP_
#define CLIENT_SESSION_HPP_

#include <participant.hpp>
#include <boost/function.hpp>
#include <handshake_message.pb.h>

namespace miu {

class client_session : public participant {
private:
	typedef participant super;

public:
	typedef boost::shared_ptr<client_session> client_session_ptr;
	typedef boost::function<void (const boost::shared_ptr<client_session>&, handshake&)> identifier_handshake_callback;

private:
	identifier_handshake_callback id_callback_;
	size_t message_total_length_;

public:
	client_session(boost::asio::io_service& io)
	: super(io) {
	}

	void set_handshake_received_callback (const identifier_handshake_callback& id_callback) {
		id_callback_ = id_callback;
	}

	//////////////////////////////////////////////////////
	//													//
	// handle handshake, first 4 bytes for identifier	//
	// length and then the session identifier string	//
	//													//
	//////////////////////////////////////////////////////

	void onConnect() {
		socket().async_read_some(boost::asio::buffer(buffer_read_.bytes, 4),		// message header length
				boost::bind(&client_session::handle_connect_1st_read,
						boost::static_pointer_cast<client_session, session> (shared_from_this()),
						boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}

	// after receiving the first batch of bytes - the message length;
	void handle_connect_1st_read(const boost::system::error_code& error, std::size_t bytes_transferred) {
		if (error) return;

		//memcpy(&message_total_length_, buffer_read_.bytes, 4);
		buffer_read_.bytes[4] = '\0';
		message_total_length_ = atoi(buffer_read_.bytes);
		buffer_read_.length = message_total_length_;

		if (message_total_length_ == 0) return;

		socket().async_read_some(boost::asio::buffer(buffer_read_.bytes, buffer_read_.length),
				boost::bind(&client_session::handle_connect_2nd_read,
						boost::static_pointer_cast<client_session, session> (shared_from_this()),
						boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}

	// after receiving the identifier message
	void handle_connect_2nd_read(const boost::system::error_code& error, size_t bytes_transferred) {
		if (error) return;

		if (bytes_transferred == buffer_read_.length) {
			//std::string identifier(buffer_read_.bytes, message_total_length_);
			handshake handshake_message;
			handshake_message.ParseFromArray(buffer_read_.bytes, message_total_length_);
			id_callback_(boost::static_pointer_cast<client_session, session> (shared_from_this()), handshake_message);
		}
		else if (bytes_transferred < buffer_read_.length) {	// incomplete read
			buffer_read_.length -= bytes_transferred;

			socket().async_read_some(
					boost::asio::buffer(buffer_read_.bytes + message_total_length_ - buffer_read_.length, buffer_read_.length),
					boost::bind(&client_session::handle_connect_2nd_read,
							boost::static_pointer_cast<client_session, session> (shared_from_this()),
							boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
		}
		else {
			std::cout << "something terribly wrong here - should never happen" << std::endl;
		}
	}

	////////////////////////////////////////////////
	//											  //
	//	reply client application that connection  //
	//  could not be established				  //
	//											  //
	////////////////////////////////////////////////
	void handshake_error(const std::string& reason) {
		std::string error_message = "#PROXY_ERROR#" + reason;

		socket().async_send(boost::asio::buffer(error_message),
				boost::bind(&client_session::handle_handshake_reply,
						boost::static_pointer_cast<client_session, session> (shared_from_this()),
						boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)
		);
	}

	void handshake_ok() {
		std::string ok_message = "#OK#";

		socket().async_send(boost::asio::buffer(ok_message),
				boost::bind(&client_session::handle_handshake_reply,
						boost::static_pointer_cast<client_session, session> (shared_from_this()),
						boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred)
		);
	}

	void handle_handshake_reply(const boost::system::error_code& error, size_t bytes_transferred) {
	}
};

}	// namespace miu

#endif /* CLIENT_SESSION_HPP_ */
