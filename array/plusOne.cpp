/* Copyright 2015 Edmund Liu

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/

#include <vector>
#include <iostream>

using namespace std;

// print the vector
void printVector(const vector<int>& a) {
    cout << "[";
    vector<int>::const_iterator it;
    for (it = a.begin(); it != a.end()-1; it++)
        cout << *it << " ";
    cout << *it << "]" << endl;
}

vector<int> plusOne(vector<int>& digits) {
    vector<int>::reverse_iterator it;
    int carry = 1;
    for (it = digits.rbegin(); it != digits.rend(); it++) {
        *it = (*it+carry);
        carry = *it/10;
        *it %= 10;
    }
    if (carry > 0)
        digits.insert(digits.begin(), carry);
    return digits;
}

int main() {
    int a[] = {9, 9, 9, 9, 9};
    vector<int> digits(a, a+5);
    printVector(digits);

    vector<int> result = plusOne(digits);
    printVector(result);
    return 0;
}
