/* Copyright 2015 Edmund Liu

Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.

Here are few examples.
[1,3,5,6], 5 → 2
[1,3,5,6], 2 → 1
[1,3,5,6], 7 → 4
[1,3,5,6], 0 → 0
*/

#include <vector>
#include <iostream>

using namespace std;

int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    if (n == 0) return 0;
    if (target <= nums.front()) return 0;
    if (target > nums.back()) return n;
    int start = 0, end = n;
    int mid = (end+start)/2;
    while (end - start > 1) {
        if (target <= nums[mid]) end = mid;
        else start = mid;
        mid = (end+start)/2;
    }
    return end;
}

int main() {
    int a[] = {1, 3, 5, 6, 8};
    vector<int> nums(a, a+5);
    cout << searchInsert(nums, 4);
    return 0;
}
