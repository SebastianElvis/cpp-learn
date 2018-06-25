#include "mt19937.h"
#include <iostream>

using namespace std;

MT19937::MT19937(int seed)
{
    MT[0] = seed;
    for(int i=1;i<MT_LEN;i++) {
        MT[i] = 1812433253 * ( MT[i-1] ^ (MT[i-1] >> 30) ) + i;
    }
}

void MT19937::twist() 
{
    for(int i=0;i<MT_LEN;i++) {
        int y = (MT[i] & 0x80000000) + (MT[(i+1)%624] & 0x7fffffff);
        MT[i] = MT[(i+397)%624] ^ (y >> 1);
        if (y%2 != 0) {
            MT[i] = MT[i] ^ 0x9908b0df;
        }
    }
}

int MT19937::next() 
{
    if( index == 0 ) twist();

    int y = MT[index];
    y = y ^ (y >> 11);
    y = y ^ ((y << 7) & 0x9d2c5680);
    y = y ^ ((y << 15) & 0xefc60000);
    y = y ^ (y >> 18);

    index = (index+1) % 624;
    return y;
}

int main() {
    MT19937 mt(0);
    for(int i=0;i<1000;i++) {
        cout << mt.next() << " ";
    }
    cout << endl;
}