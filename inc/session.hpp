/*
 * session.hpp
 *
 *  Created on: May 25, 2012
 *      Author: xingzhi
 */

#ifndef SESSION_HPP_
#define SESSION_HPP_

#define MAX_BUFFER_SIZE 2048

#include <iostream>
#include <deque>
#include <boost/asio.hpp>
#include <boost/bind.hpp>
#include <boost/shared_ptr.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <boost/asio.hpp>
#include <boost/thread.hpp>

namespace miu {

struct raw_data {
	char bytes[MAX_BUFFER_SIZE];
	int length;
};

class session : public boost::enable_shared_from_this<session> {
private:
	boost::asio::ip::tcp::socket socket_;

protected:
	// buffer for read
	raw_data buffer_read_;

	// buffered outgoing messages. it's better to use a lock-free queue
	// check "send" section for details;
	std::deque<raw_data> buffer_write_queue_;

public:
	session(boost::asio::io_service& io_service)
	: socket_(io_service) {
	}

	virtual ~session() {
		disconnect();
	}

	boost::asio::ip::tcp::socket& socket() {
		return socket_;
	}

	//////////////////////////////////////////////////////////////////
	//	3.5 key events that a session should care
	//	0. accept / connect;
	// 	1. close, shutdown, error(read == 0);
	//	2. read/receive
	//	3. (0.5) write to OS buffer
	//////////////////////////////////////////////////////////////////

	virtual void onDisconnect() = 0;
	virtual void onError() = 0;
	virtual void onReceive(raw_data& data) = 0;

	virtual void onConnect() {
		std::cout << "on Connected " << std::endl;
		this->async_read();
	}

	virtual void disconnect() {
		try {
			socket_.close();
		} catch (std::exception& e) { }
	}

	////////////////////////////////////////////////////////////
	//	read
	////////////////////////////////////////////////////////////

	void async_read() {
		socket_.async_read_some(boost::asio::buffer(buffer_read_.bytes, MAX_BUFFER_SIZE),
				boost::bind( &session::handle_read, shared_from_this(),
						boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
	}

	void handle_read(const boost::system::error_code& error, std::size_t bytes_transferred) {
		if (!error) {
			buffer_read_.length = bytes_transferred;

			std::cout << "Recv:" << bytes_transferred << " bytes" << std::endl;

			this->onReceive(buffer_read_);

			this->async_read();
		}
		else {
			std::cout << "error in reading data" << std::endl;
			this->onError();
		}
	}


	////////////////////////////////////////////////////////////
	//	send
	//	Lock should be provided here if there are more than one
	//	thread in the io_service's thread pool;
	//	Or use a lock free queue;
	////////////////////////////////////////////////////////////

	virtual void send(raw_data& data) {
		bool write_in_progress = !buffer_write_queue_.empty();
		buffer_write_queue_.push_back(data);
		if (!write_in_progress) {
			socket_.async_write_some(
					boost::asio::buffer(buffer_write_queue_.front().bytes, buffer_write_queue_.front().length),
					boost::bind(&session::handle_write, shared_from_this(),
							boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
		}
	}

	void handle_write(const boost::system::error_code& error, std::size_t bytes_transferred) {
		if (!error) {
			buffer_write_queue_.pop_front();
			if (!buffer_write_queue_.empty()) {
				socket_.async_write_some(
						boost::asio::buffer(buffer_write_queue_.front().bytes, buffer_write_queue_.front().length),
						boost::bind(&session::handle_write, shared_from_this(),
								boost::asio::placeholders::error, boost::asio::placeholders::bytes_transferred));
			}
		}
		else {
			std::cout << "error in writing data" << std::endl;
			this->onError();
		}
	}
};

} // namespace miu

#endif /* SESSION_HPP_ */
