/*
 * io_db.cpp
 *
 *  Created on: 13 Apr 2018
 *      Author: elvis
 */

#include "leveldb/db.h"
#include <iostream>

using namespace std;

int main() {
	leveldb::DB *db;
	leveldb::Options options;
	options.create_if_missing = false;
	leveldb::Status s = leveldb::DB::Open(
			options, "./tmp/testdb", &db);

	if(s.ok()) {
		cout << "Opened DB successfully!" << endl;

		s = db->Put(leveldb::WriteOptions(), "k1", "fuck");
		if(s.ok()) {
			cout << "Inserted {k1:fuck} successfully!" << endl;
		}

		string val;
		s = db->Get(leveldb::ReadOptions(), "k1", &val);

		if(s.ok()) {
			cout << "The value of key k1 is: " << val << endl;
		}
	} else {
		cout << "Failed opening DB" << endl;
	}
}
