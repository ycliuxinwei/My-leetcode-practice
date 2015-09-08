// Copyright 2015 Edmund Liu
#include <limits.h>
#include <iostream>
using namespace std;

/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321

Have you thought about this?

Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!

If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.

Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?

For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
*/
int reverse(int x) {
    if (x == INT_MIN) {
        cout << "invalid input: " << INT_MIN << endl;
        return 0;
    }
    if (x < 0) return -reverse(-x);
    int result = 0;
    while (x > 0) {
        // equals to "result*10 + x%10 > INT_MAX", avoid to compute an overflowing 'result'
        if ((INT_MAX-x%10)/10 < result) { 
            cout << "integer overflows: " << INT_MAX << endl;
            return 0;
        }
        result = result*10 + x%10;
        x /= 10;
    }
    return result;
}

int main() {
    int a = 1534236469;
    cout << "reverse " << a << ": " << reverse(a) << endl;
    cout << "-----" << endl;

    a = 1534;
    cout << "reverse " << a << ": " << reverse(a) << endl;
    cout << "-----" << endl;

    a = -1534;
    cout << "reverse " << a << ": " << reverse(a) << endl;
    cout << "-----" << endl;

    a = INT_MIN;
    cout << "reverse " << a << ": " << reverse(a) << endl;

    return 0;
}
