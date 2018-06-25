#include <iostream>
#include <stack>

using namespace std;

void reverse_str(string &str);

int main(){
    string str = "fuck you";
    reverse_str(str);
    cout << str << endl;
}

void reverse_str(string &str){
    stack<char> s;
    for(string::iterator it=str.begin();it!=str.end();it++){
        s.push((*it));
    }
    string newstr = "";
    while(!s.empty()){
        newstr += s.top();
        s.pop();
    }
    str = newstr;
}
