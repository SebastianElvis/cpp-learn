/*
 * swap.cpp
 *
 *  Created on: 5 Feb 2018
 *      Author: elvis
 */
#include <iostream>

using namespace std;

template<typename T>
void swap1(T &a, T &b){
	T tmp;
	tmp = a;
	a = b;
	b = tmp;
}

int main(){
	int a=1, b=2;
	cout << "a: " << a << " b: " << b << endl;
	swap1<int>(a, b);
	cout << "a: " << a << " b: " << b << endl;
	return 0;
}
