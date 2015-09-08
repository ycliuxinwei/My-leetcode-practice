#include <vector>
#include <iostream>
using namespace std;

/*
Given an array of n positive integers and a positive integer s, find the minimal length of a subarray of which the sum ¡Ý s. If there isn't one, return 0 instead.

For example, given the array [2,3,1,2,4,3] and s = 7, the subarray [4,3] has the minimal length under the problem constraint.
*/
int minSubArrayLen(int s, vector<int>& nums) {
	int n = nums.size();
	if (n == 0) return 0;
	int minlen = n + 1, sum = 0;
	int start = 0, end = 0;
	while (end < n) {
		while (sum < s && end < n) {
                sum += nums[end];
                end++;
        }
		while (sum >= s) {
            minlen = minlen < (end - start) ? minlen : (end - start);
            sum -= nums[start];
            start++;
        }
	}
	if (minlen == n+1) return 0;
	return minlen;
}

int main() {
	int a[] = {2, 3, 1, 7, 3, 4};
	vector<int> nums(a, a+6);
	cout << minSubArrayLen(7, nums) << endl;

	return 0;
}