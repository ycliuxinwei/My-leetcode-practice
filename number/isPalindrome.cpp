/* Copyright 2015 Edmund
Determine whether an integer is a palindrome. Do this without extra space.

Some hints: Could negative integers be palindromes? (ie, -1)

If you are thinking of converting the integer to string, note the restriction of using extra space. You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case? There is a more generic way of solving this problem.
*/

#include <iostream>
using namespace std;

bool isPalindrome(int x) {
    if(x < 0) return false;
    if(x == 0) return true;
    int tmp = x, y = 0;
    while(tmp) {
        y = 10*y + tmp%10;
        tmp /= 10;
    }
    return x == y;
}

bool isPalindromeImproved(int x) {
    if(x == 0) return true;
    if(x < 0 || x%10 == 0) return false;
    int y = 0;
    while(x > y) {
        y = 10*y + x%10;
        x /= 10;
    }
    return (x == y || x == y/10);
}

inline void print(int a) {
    cout << a;
    if(isPalindromeImproved(a))
        cout << "\tis ";
    else
        cout << "\tis not ";
    cout << "a palindrome number." << endl;
}

int main() {
    int a = 123321;
    print(a);
    a = 123345;
    print(a);
    a = -121;
    print(a);
    a = 0;
    print(a);
    return 0;
}
