// Copyright 2015 Edmund Liu
#include <math.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

/*
Given a set of distinct integers, nums, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.

For example, If nums = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1, 2, 3],
  [1, 3],
  [2, 3],
  [1, 2],
  []
]
*/

// print the vector
void printVector(const vector<int>& a) {
    cout << "[";
    vector<int>::const_iterator it;
    for (it = a.begin(); it != a.end()-1; it++)
        cout << *it << " ";
    cout << *it << "]" << endl;
}

// print subsets
void printSubsets(const vector<vector<int> >& matrix) {
    int n = matrix.size();
    cout << "[\n";
    for (int i = 0; i < n; i++) {
        vector<int>::const_iterator it;
        cout << " [";
        if (!matrix[i].empty()) {
            for (it = matrix[i].begin(); it != matrix[i].end()-1; it++)
                cout << *it << ", ";
            cout << *it;
        }
        cout << "]\n";
    }
    cout << "]" << endl;
}

/* recursive (backtracking)
-> [1] -> [1, 2] -> [1, 2, 3]
       <-        <-
       -> [1, 3]
<-     <-
-> [2] -> [2, 3]
<-     <-
-> [3]
*/
void genSubsets(const vector<int>& nums, int start,
                vector<int>& sub, vector<vector<int> >& subs) {
    subs.push_back(sub);
    for (int i = start; i < nums.size(); i++) {
        sub.push_back(nums[i]);
        // cout << "*"; printVector(sub);
        genSubsets(nums, i + 1, sub, subs);
        // printVector(sub);
        // cout << "*" << endl;
        sub.pop_back();
    }
}
vector<vector<int> > subsets1(vector<int>& nums) {
    vector<vector<int> > subs;
    vector<int> sub;
    sort(nums.begin(), nums.end());
    genSubsets(nums, 0, sub, subs);
    return subs;
}

/* Iterative
This problem can also be solved iteratively. Take [1, 2, 3] in the problem statement as an example. The process of generating all the subsets is like:

                      []
i = 0(n = 1), j = 0   [1]
i = 1(n = 2), j = 0   [2]
            , j = 1   [1, 2]
i = 2(n = 4), j = 0   [3]
            , j = 1   [1, 3]
            , j = 2   [2, 3]
            , j = 3   [1, 2, 3]
*/
vector<vector<int> > subsets2(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    vector<vector<int> > subs(1, vector<int>());
    for (int i = 0; i < nums.size(); i++) {
        int n = subs.size();
        for (int j = 0; j < n; j++) {
            subs.push_back(subs[j]);
            subs.back().push_back(nums[i]);
        }
    }
    return subs;
}

/*Bit Manipulation

This is the most clever solution that I have seen. The idea is that to give all the possible subsets, we just need to exhaust all the possible combinations of the numbers. And each number has only two possibilities: either in or not in a subset. And this can be represented using a bit.

There is also another a way to visualize this idea. That is, if we use the above example, 1 appears once in every two consecutive subsets, 2 appears twice in every four consecutive subsets, and 3 appears four times in every eight subsets, shown in the following (initially the 8 subsets are all empty):

[], [], [], [], [], [], [], []
[], [1], [], [1], [], [1], [], [1]
[], [1], [2], [1, 2], [], [1], [2], [1, 2]
[], [1], [2], [1, 2], [3], [1, 3], [2, 3], [1, 2, 3]
*/
vector<vector<int> > subsets3(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int num_subset = pow(2, nums.size());
    vector<vector<int> > res(num_subset, vector<int>());
    for (int i = 0; i < nums.size(); i++)
        for (int j = 0; j < num_subset; j++)
            if ((j >> i) & 1)
                res[j].push_back(nums[i]);
    return res;
}

int main() {
    int a[] = {1, 3, 2};
    vector<int> nums(a, a+3);
    vector<vector<int> > result;

    result = subsets1(nums);
    printSubsets(result);

    result = subsets2(nums);
    printSubsets(result);

    result = subsets3(nums);
    printSubsets(result);

    return 0;
}
