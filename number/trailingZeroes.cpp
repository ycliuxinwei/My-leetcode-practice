/* Copyright 2015 Edmund Liu

Given an integer n, return the number of trailing zeroes in n!.

Note: Your solution should be in logarithmic time complexity.

*/
#include <iostream>

using namespace std;

int trailingZeroes(int n) {
    int result = 0;
    while (n > 4) {
        result += n/5;
        n /= 5;
        cout << result;
    }
    return result;
}

int main() {
    cout << trailingZeroes(126);

    return 0;
}
