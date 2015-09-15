/* Copyright 2015 Edmund Liu

The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.

For example, There exist two distinct solutions to the 4-queens puzzle:

Solution 1: [".Q..", "...Q", "Q...", "..Q."]
Solution 2: ["..Q.", "Q...", "...Q", ".Q.."]
*/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

// print the matrix
void printMatrix(const vector<vector<string> >& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    for (int i = 0; i < n; i++) {
        vector<string>::const_iterator it;
        for (it = matrix[i].begin(); it != matrix[i].end(); it++)
            cout << *it << endl;
        cout << endl;
    }
}

void buildChess(const vector<int>& a, vector<vector<string> >& b, int n) {
    b.push_back(vector<string>(0));
    for (int i = 0; i < n; i++) {
        string s = "";
        for (int j = 0; j < n; j++) {
            if(a[i] == j+1)
                s += "Q";
            else
                s += ".";
        }
        b.back().push_back(s);
    }
}

bool Check(const vector<int>& a, int n) {
    for(int i = 0; i < n; i++)
        if(abs(a[i]-a[n]) == n-i || a[i] == a[n])
            return false;
    return true;
}

vector<vector<string> > solveNQueens(int n) {
    int i = 0, j;
    vector<vector<string> > b;
    vector<int> a(n, 0);  // 'a[i]' means the position of the queen in line 'i'
    while(i >= 0) {
        for(a[i]++; a[i] <= n; a[i]++)
            if(Check(a, i)) break;
        if(a[i] <= n)
            if(i == n-1) buildChess(a, b, n);
            else a[++i] = 0;
        else i--;      // backtrack
    }
    return b;
}

int main() {
    vector<vector<string> > c = solveNQueens(8);
    printMatrix(c);
    return 0;
}
