/*
 * daytime_client_sybc.cpp
 *
 *  Created on: 23 Apr 2018
 *      Author: elvis
 */

#include <iostream>
#include <boost/array.hpp>
#include <boost/asio.hpp>

using boost::asio::ip::tcp;

int main(int argc, char* argv[]) {
	try {
		if(argc != 2) {
			std::cerr << "Usage: ./daytime_cient_sync <host>" << std::endl;
			exit(0);
		}

		boost::asio::io_service io_service;

		tcp::resolver resolver(io_service);
		tcp::resolver::query query(argv[1], "daytime");
		boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::address::from_string(argv[1]), 10000);;

		tcp::socket socket(io_service);
		socket.connect(endpoint);

		while(true) {
			boost::array<char, 128> buf;
			boost::system::error_code error;

			size_t len = socket.read_some(boost::asio::buffer(buf), error);

			if(error == boost::asio::error::eof) {
				break;
			} else if (error) {
				throw boost::system::system_error(error);
			}
			std::cout << buf.data() << std::endl;
		}

	} catch (std::exception& e) {
		std::cerr << e.what() << std::endl;
	}
}
