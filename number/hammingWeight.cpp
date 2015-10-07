/* Copyright 2015 Edmund Liu

Write a function that takes an unsigned integer and returns the number of ’1' bits it has (also known as the Hamming weight).

For example, the 32-bit integer ’11' has binary representation 00000000000000000000000000001011, so the function should return 3.
*/

#include <stdint.h>
#include <iostream>
using namespace std;

int hammingWeight(uint32_t n) {
    int count = 0;
    while (n) {
        count += n & 1;
        n = n >> 1;
    }
    return count;
}

int main() {
    uint32_t a = 11;
    cout << hammingWeight(a) << endl;
    return 0;
}
