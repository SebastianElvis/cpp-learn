#include <iostream>

using namespace std;

class Test
{
    public:
        Test(){
            cout << "fuck you init " << endl;
        }

        Test(int a){
            cout << "fuck you init" << a << endl;
        }

        ~Test(){
            cout << "fuck you destroy" << endl;
        }
};

int main(){

    // without new: memory is allocated on stack
    // everything destroyed after the function invocation
    Test a; // === Test a = Test();
    Test b(1); // === Test b = Test(1);

    // with new: memory is allocated on heap
    // do not destroy automatically
    // need to use: delete
    Test *c = new Test();
    Test *d = new Test(1);
}
