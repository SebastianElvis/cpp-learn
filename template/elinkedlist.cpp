/*
 * elinkedlist.cpp
 *
 *  Created on: 3 May 2018
 *      Author: elvis
 */

#include <iostream>

using namespace std;


template<class T>
class ELinkedList
{

private:
	T elem;
	ELinkedList<T> *next = NULL;

public:

	void add(T newElem) {
		ELinkedList<T> *newList = new ELinkedList<T>;
		newList->elem = newElem;

		ELinkedList<T> *n = this;
		while(n->next != NULL) {
			n = n->next;
		}
		n->next = newList;
	}

	ELinkedList<T> * getNext() {
		return next;
	}

	T getVal() {
		return elem;
	}

};



int main() {
	ELinkedList<int> l;
	l.add(1);
	l.add(2);
	l.add(3);

	ELinkedList<int> *cur = &l;
	while (cur->getNext() != NULL) {
		cur = cur->getNext();
		cout << cur->getVal() << " ";
	}
}
