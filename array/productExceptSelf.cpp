/* Copyright 2015 Edmund Liu

Given an array of n integers where n > 1, nums, return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Solve it without division and in O(n).

For example, given [1,2,3,4], return [24,12,8,6].

Follow up:
Could you solve it with constant space complexity? (Note: The output array does not count as extra space for the purpose of space complexity analysis.)
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

/*
idx  0                          1                  2                 3
res1 1                          nums[0]            nums[0]*nums[1]   nums[0]*nums[1]*nums[2]
res2 *nums[0]*nums[1]*nums[2]   *nums[2]*nums[3]   *nums[3]          *1
*/
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> res1(n, 1), res2(n, 1);
    for (int i = 1; i < n; i++) {
        res1[i] = res1[i-1]*nums[i-1];
        res2[n-i-1] = res2[n-i]*nums[n-i];
    }
    for (int i = 0; i < n; i++)
        res1[i] = res1[i]*res2[i];
    return res1;
}

int main() {
    int a[] = {1, 2, 3, 4};
    vector<int> nums(a, a+4);
    printVector(nums);
    vector<int> result = productExceptSelf(nums);
    printVector(result);
    return 0;
}
