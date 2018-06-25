#include <iostream>
#include <thread>

// g++ thread.cpp -o thread -std=c++11 -pthread

using namespace std;

void greeting() {
    cout << "fuck you bitch" << endl;
    return;
}

int main(){
    thread t(greeting);
    t.join();
    return 0;
}
