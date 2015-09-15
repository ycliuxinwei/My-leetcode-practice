/* Copyright 2015 Edmund Liu

Given an array of size n, find the majority element. The majority element is the element that appears more than n/2 times.

You may assume that the array is non-empty and the majority element always exist in the array.
*/

#include <vector>
#include <map>
#include <algorithm>
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
Moore's voting algorithm
http://www.cs.utexas.edu/~moore/best-ideas/mjrty/index.html
*/
int majorityElementMoore(vector<int>& nums) {
    int n = nums.size();
    int major = nums[0];
    for(int i = 0, count = 0; i < n; i++){
        if(major == nums[i]) count++;
        else count--;
        if(count == -1){
            major = nums[i];
            count++;
        }
    }
    return major;
}

int majorityElement(vector<int>& nums) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    return nums[n/2];
}

int main() {
    int a[] = {3, 2, 2, 3, 4, 3, 1, 3, 5, 3, 3, 3, 4};
    vector<int> nums(a, a+13);
    cout << majorityElement(nums);
    return 0;
}
