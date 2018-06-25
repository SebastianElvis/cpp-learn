// stack/heap/static
// static area: global variables and static variables are put together here
// static area includes: .data: initialized global/static variables // .bss: uninitialized global/static variables


#include <iostream>

using namespace std;

int main()
{
    static int c; // .data
    static int d = 1; // .bss


    // static variables only exist in the file rather than other files which include this file
    // static variables only init once
    // the space is allocated when compiling
}
