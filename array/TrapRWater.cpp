// Copyright 2015 Edmund Liu
#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& a) {
    cout << "[";
    vector<int>::iterator it;
    for (it = a.begin(); it != a.end()-1; it++)
        cout << *it << " ";
    cout << *it << "]" << endl;
}

/*
Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.

For example, Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
*/
int trap(vector<int>& height) {
    int n = height.size();
    vector<int> left_max(n);
    vector<int> right_max(n);
    for (int i = 1; i < n; i++) {
        left_max[i] = max(left_max[i-1], height[i-1]);
        right_max[n-i-1] = max(right_max[n-i], height[n-i]);
    }
    int sum = 0;
    for (int i = 0; i < n; i++) {
        int minh = min(left_max[i], right_max[i]);
        if (minh>height[i])
            sum += minh - height[i];
    }
    return sum;
}

int main() {
    int a[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> nums(a, a+12);
    printVector(nums);
    int b = trap(nums);
    cout << "Water: " << b << endl;
    return 0;
}
