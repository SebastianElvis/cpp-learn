/*
 * testlist.cpp
 *
 *  Created on: 19 Feb 2018
 *      Author: elvis
 */

#include <list>
#include <iostream>
#include <string>

using namespace std;

int main(){
	list<string> lstStr;
	lstStr.push_back("Please");
	lstStr.push_back("leave");
	lstStr.push_back("a");
	lstStr.push_back("message");

	for(list<string>::iterator p=lstStr.begin();p!=lstStr.end();++p){
		cout << *p << endl;
	}

	for(list<string>::reverse_iterator p=lstStr.rbegin();p!=lstStr.rend();++p){
        cout << *p << endl;
	}

    string arrStr[5] = {"My", "cup", "cup", "fuck", " you"};

    for(string *p=&arrStr[0];p!=&arrStr[5];++p){
        cout << *p << endl;
    }

	return 0;
}
