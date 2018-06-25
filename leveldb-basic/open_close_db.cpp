/*
 * t.cpp
 *
 *  Created on: 13 Apr 2018
 *      Author: elvis
 */


#include <cassert>
#include "leveldb/db.h"
#include <iostream>

using namespace std;

int main() {
	leveldb::DB* db;
	leveldb::Options options;
	options.create_if_missing = true;
	leveldb::Status status = leveldb::DB::Open(
			options, "./tmp/testdb", &db);
	assert(status.ok());
	cout << "status: " << status.ToString() << endl;
	delete db;
}

