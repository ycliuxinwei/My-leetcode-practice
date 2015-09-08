// Copyright 2015 Edmund Liu
#include <vector>
#include <list>
#include <iostream>
using namespace std;

/*
Given an array of integers, every element appears twice except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/
int singleNumber(vector<int>& nums) {
	int siglenum = 0;
	vector<int>::iterator it;
	for (it = nums.begin(); it != nums.end(); it++)
		siglenum = siglenum xor *it;
	return siglenum;
}

/*
Given an array of integers, every element appears three times except for one. Find that single one.

Note: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?

int singleNumber2(vector<int>& nums) {
	int n = nums.size();
	int one = 0, two = 0, three = 0;
        for(int i=0; i<n; i++) {
			two |= one & nums[i];
            one ^= nums[i];
            three = one & two;
            one &= ~three;
            two &= ~three;
        }
    return one;  
}
*/
int singleNumber2(vector<int>& nums) {
	const int Len = sizeof(int)*8;
	vector<int> bits(Len, 0);
	vector<int>::iterator it;
	int Sign = 0;
	for (it = nums.begin(); it != nums.end(); it++) {
		bits[Len-1] = 0;
		if (*it > 0) bits[Len-1] = 1;
		if (*it < 0) bits[Len-1] = -1;
		Sign += bits[Len-1]; *it *= bits[Len-1];
        for (int i = 0; i < Len-1; i++) {
			bits[i] += *it % 2; *it /= 2;
        }
	}
	int result = 0, tmp;
	Sign = (Sign % 3 == 1) or (Sign % 3 == -2) ? 1 : -1;
	for (int i = 1; i < Len; i++) {
		tmp = bits[Len-i-1] % 3;
		result = result*2 + tmp;
	}
    return result*Sign;
}

/*
Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
For example: Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].

Note:
1. The order of the result is not important. So in the above example, [5, 3] is also correct.
2. Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
*/
int singleNumber3(vector<int>& nums) {
	int n = nums.size();

	return 0;
}

int main() {
	int a[] = {7,3,3,7,2,2,4};
	vector<int> nums1(a, a+7);
	cout << singleNumber(nums1) << endl;
	
	int b[] = {-401451,-177656,-2147483646,-473874,-814645,-2147483646,-852036,-457533,-401451,-473874,-401451,-216555,-917279,-457533,-852036,-457533,-177656,-2147483646,-177656,-917279,-473874,-852036,-917279,-216555,-814645,2147483645,233,2147483645,-814645,2147483645,-216555};
	vector<int> nums2(b, b+31);
	cout << singleNumber2(nums2) << endl;
	
	int c[] = {7,3,3,7,5,9,5,4};
	vector<int> nums3(c, c+8);
	//cout << singleNumber3(nums3) << endl;
	
	return 0;
}