// Copyright 2015 Edmund Liu
#include <vector>
#include <iostream>
using namespace std;

/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example, Given input array nums = [1,1,2], Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively. It doesn't matter what you leave beyond the new length.
*/
int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    if (n == 1) return 1;
    for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
        if (*it == *(it + 1) && (it + 1) != nums.end()) {
            nums.erase(it + 1);
            continue;
        }
        it++;
    }
    return nums.size();
}

/*
Follow up for "Remove Duplicates": What if duplicates are allowed at most twice?

For example, Given sorted array nums = [1,1,1,2,2,3], Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3. It doesn't matter what you leave beyond the new length.
*/
int removeDuplicates2(vector<int>& nums) {
    int n = nums.size();
    if (n <= 2) return n;
    for (vector<int>::iterator it = nums.begin(); it != nums.end();) {
        if (*it == *(it + 2) && (it + 2) < nums.end()) {
            nums.erase(it + 2);
            continue;
        }
        it++;
    }
    return nums.size();
}

int main() {
    int a[] = {1, 2, 3, 3, 4, 5, 6};
    vector<int> nums(a, a+7);
    cout << nums.size() << endl;
    cout << removeDuplicates2(nums) << endl;
    cout << removeDuplicates(nums) << endl;
    return 0;
}
