// Copyright 2015 Edmund Liu
#include <vector>
#include <iostream>
using namespace std;

void printVector(vector<int>& a) {
    cout << "[";
    vector<int>::iterator it;
    for (it = a.begin(); it != a.end()-1; it++)
        cout << *it << " ";
    cout << *it << "]" << endl;
}

/*
Given an array containing n distinct numbers taken from 0, 1, 2, ..., n, find the one that is missing from the array.

For example, Given nums = [0, 1, 3] return 2.

Note:
Your algorithm should run in linear runtime complexity. Could you implement it using only constant extra space complexity?

solution 1: using 'xor', if the integer appears only once, then it will be the result.
int missingNumber(vector<int>& nums) {
    int missing = 0, i = 0;
    vector<int>::iterator it;
    for(it = nums.begin(); it!=nums.end(); it++) {
        i = i+1;
        missing = missing xor *it xor i;
    }
    return missing;
}

solution 2:
*/
int missingNumber(vector<int>& nums) {
    int sum = 0, n = nums.size();
    vector<int>::iterator it;
    for(it = nums.begin(); it != nums.end(); it++)
        sum += *it;
    int missing = (0+n)*(n+1)/2 - sum;
    return missing;
}

int main() {
    int a[] = {0, 1, 3, 4, 5, 6};
    vector<int> nums(a, a+6);
    printVector(nums);
    int i = 0;
    cout << "the missing number is: " << missingNumber(nums) << endl;
    return 0;
}
