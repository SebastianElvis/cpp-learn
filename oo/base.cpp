/*
 * base.cpp
 *
 *  Created on: 3 May 2018
 *      Author: elvis
 */

#include <iostream>

using namespace std;

class Base {
public:
	short baseMember;
	void setBaseMember(short baseValue){
		baseMember = baseValue;
	}
	void fuck(){
		cout << "Base fuck()" << endl;
	}
	// virtual void fuck() = 0; pure virtual function
};


class Derived : public Base {
public:
	short derivedMember;
	void setDerivedMember(short derivedValue){
		derivedMember = derivedValue;
	}
	~Derived() {
		cout << "fuck you" << endl;
	}

	void fuck() {
		cout << "Derived fuck()" << endl;
	}
};



int main() {
	Base *basePtr = new Derived;

	// if fuck() not virtual -> print Base fuck()
	// if fuck() virtual -> print Derived fuck()
	basePtr->fuck();
	//derivedPtr->fuck();

}

