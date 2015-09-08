/* Copyright 2015 Edmund Liu

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

1. Integers in each row are sorted from left to right.
2. The first integer of each row is greater than the last integer of the previous row.

For example, consider the following matrix:

[
  [1,   3,  5,  7],
  [10, 11, 16, 20],
  [23, 30, 34, 50]
]
Given target = 3, return true.
*/

#include <vector>
#include <iostream>
using namespace std;

// generate a matrix
vector<vector<int> > genMatrix() {
    vector<vector<int> > matrix(3, vector<int>(4));
    int a[] = {1, 3, 5, 7, 10, 11, 16, 20, 23, 30, 34, 50};
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++)
            matrix[i][j] = a[i*4+j];
    }
    return matrix;
}

// print the matrix
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
}

bool searchMatrix(const vector<vector<int> >& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    if(matrix.empty() || matrix[0].empty())
        return false;
    if (target < matrix[0][0] || target > matrix[m-1][n-1])
        return false;
    int i;
    for (i = 0; i < m-1; i++)
        if(target >= matrix[i][0] && target < matrix[i+1][0])
            break;
    for (int j = 0; j < n; j++)
        if (target == matrix[i][j]) return true;
    return false;
}

int main() {
    vector<vector<int> > matrix(genMatrix());
    printMatrix(matrix);
    cout << searchMatrix(matrix, 34);
    return 0;
}
