/*
 * timer2.cpp
 *
 *  Created on: 23 Apr 2018
 *      Author: elvis
 */


#include <iostream>
#include <boost/asio.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

void print(const boost::system::error_code&) {
	std::cout << "Hello World!" << std::endl;
}

int main() {
	boost::asio::io_service io;

	boost::asio::deadline_timer t(io, boost::posix_time::seconds(5));

	t.async_wait(&print);

	io.run();

	return 0;
}
