/*
 * testplus.cpp
 *
 *  Created on: 3 May 2018
 *      Author: elvis
 */

#include <iostream>

using namespace std;

class MyInt {
public:
	int x = 10;

	int operator+(MyInt a) {
		return (a.x+x);
	}
};


int main() {
	MyInt m1, m2;
	cout << m1+m2 << endl;
}

