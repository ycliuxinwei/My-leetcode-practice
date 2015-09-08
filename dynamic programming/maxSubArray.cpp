#include <vector>
#include <iostream>
using namespace std;

void printVector(vector<int>& a) {
	cout << "[";
	vector<int>::iterator it;
	for (it=a.begin(); it!=a.end()-1; it++)
		cout << *it << " ";
	cout << *it << "]" << endl;
}

/*
Find the contiguous sub-array within an array (containing at least one number) which has the largest sum.

For example, given the array [−2,1,−3,4,−1,2,1,−5,4], the contiguous sub-array [4,−1,2,1] has
the largest sum = 6.
*/
int maxSubArray(vector<int>& nums) {
	int n = nums.size();
	int sum = nums[0]; int subArrwith_nums = nums[0];
	for(int i = 1; i < n; i++) {
		subArrwith_nums = max(subArrwith_nums + nums[i], nums[i]);
		sum = max(sum,subArrwith_nums);
	}
	return sum;
}

int main() {
	int a[] = {-2,1,-3,4,-1,2,1,-5,4};
	vector<int> nums(a, a+9);
	printVector(nums);
	cout << "the largest sum = " << maxSubArray(nums) << endl;
	return 0;
}