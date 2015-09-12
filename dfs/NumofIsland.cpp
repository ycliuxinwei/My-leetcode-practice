/* Copyright 2015 Edmund Liu

Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

Example 1:
11110
11010
11000
00000
Answer: 1

Example 2:
11000
11000
00100
00011
Answer: 3

*/

#include <vector>
#include <string>
#include <iostream>
using namespace std;

// print the matrix
void printMatrix(const vector<vector<char> >& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    cout << "[>>>>" << endl;
    for (int i = 0; i < n; i++) {
        vector<char>::const_iterator it;
        for (it = matrix[i].begin(); it != matrix[i].end(); it++)
            cout << *it;
        cout << endl;
    }
    cout << "<<<<]" << endl;
}

bool check(vector<vector<char> >& grid, int i, int j) {
    int m = grid.size();
    int n = grid[0].size();
    if (i >= 0 && i < m && j >= 0 && j < n)
        if (grid[i][j] == '1') return false;
    return true;
}

void DFS(vector<vector<char> >& grid, int i, int j) {
    if (check(grid, i, j)) return;
    grid[i][j] = 'v';
    DFS(grid, i+1, j);
    DFS(grid, i-1, j);
    DFS(grid, i, j+1);
    DFS(grid, i, j-1);
}

int numIslands(vector<vector<char> >& grid) {
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            if (grid[i][j] == '1') {
                count++;
                DFS(grid, i, j);
            }
    return count;
}

int main() {
    vector<vector<char> > a(4, vector<char>(5));
    vector<vector<char> > b(4, vector<char>(5));
    string str1 = "11110110101100000000";
    string str2 = "11000110000010000011";
    for (int i = 0; i < 4; i++)
        for (int j = 0; j < 5; j++) {
            a[i][j] = str1[i*5+j];
            b[i][j] = str2[i*5+j];  
        }
    printMatrix(a);
    printMatrix(b);
    cout << numIslands(a) << endl;
    cout << numIslands(b) << endl;
    
    return 0;
}
