/* Copyright 2015 Edmund Liu

Rotate an array of n elements to the right by k steps.

For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].

Note: Try to come up as many solutions as you can, there are at least 3 different ways to solve this problem.

Hint: Could you do it in-place with O(1) extra space?

*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// print the vector
void printVector(const vector<int>& a) {
    cout << "[";
    vector<int>::const_iterator it;
    for (it = a.begin(); it != a.end()-1; it++)
        cout << *it << " ";
    cout << *it << "]" << endl;
}

/* print the matrix
void printMatrix(const vector<vector<int> >& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    cout << "[>>>>>>>>>>" << endl;
    for (int i = 0; i < n; i++) {
        vector<int>::const_iterator it;
        for (it = matrix[i].begin(); it != matrix[i].end()-1; it++)
            cout << *it << "\t";
        cout << *it << endl;
    }
    cout << "<<<<<<<<<<]" << endl;
} */

/* print the string from end to start
void revPrintString(const string& str) {
    string::reverse_iterator it;
    for (it = str.rbegin(); it != str.rend(); it++)
        cout << *it;
    cout << endl;
} */

// normal way, Time Limit Exceeded
void rotate1(vector<int>& nums, int k) {
    int n = nums.size(), tmp;
    if(n == 0 || k == 0) return;
    k = k % n;
    for (int i = 0; i < n-k; i++) {
        tmp = nums[0];
        for (int j = 0; j < n-1; j++)
            nums[j] = nums[j+1];
        nums[n-1] = tmp;
    }
}

// Time Limit Exceeded
void rotate2(vector<int>& nums, int k) {
    int n = nums.size(), tmp;
    if(n == 0 || k == 0) return;
    k = k % n;
    for (int i = 0; i < k; i++)
        swap(nums[i], nums[i+n-k]);
    for (int i = n-k; i < n; i++) {
        tmp = nums[n-1];
        for (int j = n-1; j > k; j--)
            nums[j] = nums[j-1];
        nums[k] = tmp;
    }
}

// 
void rotate3(vector<int>& nums, int k) {
    int n = nums.size();
    if(n == 0 || k == 0) return;
    k = k % n;
    vector<int> tmp(k);
    for (int i = 0; i < k; i++)
        tmp[i] = nums[i+n-k];
    for (int j = 0; j < n-k; j++)
        tmp.push_back(nums[j]);
    nums = tmp;
}

// BA = reverse(reverse(A)reverse(B))
void rotate4(vector<int>& nums, int k) {
    int n = nums.size();
    if(n == 0 || k == 0) return;
    k = k % n;
    reverse(nums.begin(), nums.begin()+n-k);
    reverse(nums.begin()+n-k, nums.end());
    reverse(nums.begin(), nums.end());
}


Here use a example input array [1,2,3,4,5,6,7,8] (n = 8) to explain:

1.suppose k = 3:

GCD = gcd(3,8) = 1, which means there is only one path.

Count = (n / GCD) - 1 = 7, which means we need 7 swaps to finish the path. (actually for a path have x element, we need x - 1 swaps)

Then we can simulate the process of the algorithm,

path0(each time swap index0 element and indexPosition element):
[*1* 2  3 *4* 5  6  7  8 ] (position = 3) -> 
[*4* 2  3  1  5  6 *7* 8 ] (position = 6) ->
[*7**2* 3  1  5  6  4  8 ] (position = 1) ->
[*2* 7  3  1 *5* 6  4  8 ] (position = 4) ->
[*5* 7  3  1  2  6  4 *8*] (position = 7) ->
[*8* 7 *3* 1  2  6  4  5 ] (position = 2) ->
[*3* 7  8  1  2 *6* 4  5 ] (position = 5) ->
[ 6  7  8  1  2  3  4  5 ] -> finished
total 7 times swap. Final result [6,7,8,1,2,3,4,5]

2.suppose k = 2:

Similary, GCD = 2, which means there are 2 paths.

count = 3, which means we need 3 swaps to finish each path.

Give the process:

path0(swap index0 and position element):

[*1* 2 *3* 4  5  6  7  8 ] (position = 2) ->
[*3* 2  1  4 *5* 6  7  8 ] (position = 4) ->
[*5* 2  1  4  3  6 *7* 8 ] (position = 6) ->
[ 7  2  1  4  3  6  5  8 ]
-> path0 finished

Then we continue processing path1(swap index1 and position element):

[ 7 *2* 1 *4* 3  6  5  8 ] (position = 3) ->
[ 7 *4* 1  2  3 *6* 5  8 ] (position = 5) ->
[ 7 *6* 1  2  3  4  5 *8*] (position = 7) ->
[ 7  8  1  2  3  4  5  6 ]
-> path1 finished

-> all path finished

we get the result [7,8,1,2,3,4,5,6]
*/
int findGcd(int a, int b) {
    return (a == 0 || b == 0) ? a+b : findGcd(b, a%b);
}
void rotate5(vector<int>& nums, int k) {
    int n = nums.size();
    if(n <= 1) return;
    int step = k % n;
    int gcd = findGcd(n, step);  // find GCD between nums length and step
    int position, count;
    //gcd path to finish movie
    for(int i = 0; i < gcd; i++) {
        position = i;  // beginning position of each path
        count = n/gcd - 1;  // count is the number we need swap each path
        for(int j = 0; j < count; j++){
            position = (position + step) % n;
            swap(nums[i], nums[position]);  // swap index value in index i and position
          /*nums[i] ^= nums[position];
            nums[position] ^= nums[i];
            nums[i] ^= nums[position];*/
        }
    }
}

int main() {
    int a[] = {1, 2, 3, 4, 5, 6, 7};
    vector<int> nums(a, a+7);
    rotate5(nums, 5);
    printVector(nums);
    return 0;
}
