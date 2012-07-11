/*
 * participant.hpp
 *
 *  Created on: May 27, 2012
 *      Author: xingzhi
 */

#ifndef PARTICIPANT_HPP_
#define PARTICIPANT_HPP_

#include <session.hpp>

namespace miu {

class participant;

class session_event_handler {
public:
	virtual ~session_event_handler() { }
	virtual void on_session_ended(participant * participant) = 0;
	virtual void on_session_connected(participant * participant) = 0;
	virtual void on_session_error(participant * participant) = 0;
};

class participant : public session {
protected:
	typedef session super;
public:
	typedef boost::shared_ptr<participant> this_ptr_type;
public:
	session_event_handler * handler;
	this_ptr_type counter_party_session;

public:
	participant(boost::asio::io_service& io_service)
		: super(io_service), handler(NULL) {
	}

	virtual void onReceive(raw_data& data) {
		if (counter_party_session) {
			counter_party_session->send(data);
		}
		else {
			std::cout << "no counter party session to forward data" << std::endl;
		}
	}

	virtual void onConnect() {
		super::onConnect();
		handler->on_session_connected(&(*this));
	}

	virtual void onDisconnect() {
		handler->on_session_ended(&(*this));
	}

	virtual void onError() {
		handler->on_session_error(&(*this));
	}
};

}

#endif /* PARTICIPANT_HPP_ */
