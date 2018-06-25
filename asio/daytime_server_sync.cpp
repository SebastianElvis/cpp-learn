/*
 * daytime_server_sync.cpp
 *
 *  Created on: 23 Apr 2018
 *      Author: elvis
 */

#include <iostream>
#include <ctime>
#include <string>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

std::string make_daytime_string() {
	std::time_t now = time(0);
	return std::ctime(&now);
}

int main() {
	try {
		boost::asio::io_service io_service;
		tcp::acceptor acceptor(io_service, tcp::endpoint(tcp::v4(), 10000));

		while(true) {
			tcp::socket socket(io_service);
			acceptor.accept(socket);

			std::string msg = make_daytime_string();

			boost::system::error_code ignored_error;
			boost::asio::write(socket, boost::asio::buffer(msg), ignored_error);
		}
	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}

	return 0;
}
