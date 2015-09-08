/* Copyright 2015 Edmund Liu

Given an integer, write a function to determine if it is a power of two.

*/

#include <iostream>
using namespace std;

bool isPowerOfTwo1(int n) {
    if (n <= 0) return false;
    while (n%2 == 0)
        n = n/2;
    return n == 1;
}

/*
00010000000000000000000000000000
                                 & = 00000000000000000000000000000000
00001111111111111111111111111111
*/
bool isPowerOfTwo2(int n) {
    return n > 0 && !(n&(n-1));
}

int main() {
    cout << isPowerOfTwo1(88) << endl;
    cout << isPowerOfTwo2(64) << endl;
    return 0;
}
