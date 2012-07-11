/*
 * application.hpp
 *
 *  Created on: May 26, 2012
 *      Author: xingzhi
 */

#ifndef APPLICATION_HPP_
#define APPLICATION_HPP_

#include <cstdlib>
#include <proxy_server.hpp>

#define DEFAULT_PROXY_LISTENER_PORT 28572

namespace miu {

class application {
private:
	boost::shared_ptr<proxy_server> proxy_server_;

private:
	void usage(char* cmd) {
		printf("Usage:\n  %s [-p port]\n", cmd);
		std::abort();
	}

	int read_port_options(int argc, char *argv[]) {
		int i = 1, port = DEFAULT_PROXY_LISTENER_PORT;
		while (i < argc - 1) {
			if (strcmp(argv[i], "-p") == 0 && (atoi(argv[i+1]) > 0) ) {
				port = atoi(argv[i+1]);
				i += 2;
			}
			else {
				usage(argv[0]);
			}
		}
		return port;
	}

public:
	application(int argc, char *argv[]) {
		int port = read_port_options(argc, argv);
		proxy_server_ = boost::shared_ptr<proxy_server>(new proxy_server(port));
	}

	void run() {
		proxy_server_->run();

		while(true) {
			sleep(1);
		}

		shutdown();
	}

	void shutdown() {
		proxy_server_->shutdown();
	}
};

}	// namespace miu

#endif /* APPLICATION_HPP_ */
