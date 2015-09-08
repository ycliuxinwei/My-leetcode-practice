/* Copyright 2015 Edmund Liu

Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:

1. Integers in each row are sorted in ascending from left to right.
2. Integers in each column are sorted in ascending from top to bottom.

For example, consider the following matrix:

[
  [1,   4,  7, 11, 15],
  [2,   5,  8, 12, 19],
  [3,   6,  9, 16, 22],
  [10, 13, 14, 17, 24],
  [18, 21, 23, 26, 30]
]

Given target = 5, return true.
Given target = 20, return false.
*/

#include <vector>
#include <iostream>
using namespace std;

// generate a matrix
vector<vector<int> > genMatrix() {
    vector<vector<int> > matrix(5, vector<int>(5));
    int a[] = {1, 4, 7, 11, 15, 2, 5, 8, 12, 19, 3, 6, 9, 16, 22, 10, 13, 14, 17, 24, 18, 21, 23, 26, 30};
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++)
            matrix[i][j] = a[i*5+j];
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
    int row = 0, col = n-1;
    while (row <= m-1 && col >= 0) {
        if (matrix[row][col] == target) return true;
        else if (matrix[row][col] < target) row += 1;
        else col -= 1;
    }
    return false;
}

int main() {
    vector<vector<int> > matrix(genMatrix());
    printMatrix(matrix);
    cout << searchMatrix(matrix, 5) << endl;

    vector<vector<int> > matrix2(1, vector<int>(1,4));
    printMatrix(matrix2);
    cout << searchMatrix(matrix2, 4);
    return 0;
}
