/* Copyright 2015 Edmund Liu

Follow up for N-Queens problem. Now, instead outputting board configurations, return the total number of distinct solutions.
*/

#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

bool Check(const vector<int>& a, int n) {
    for(int i = 0; i < n; i++)
        if(abs(a[i]-a[n]) == n-i || a[i] == a[n])
            return false;
    return true;
}

int solveNQueens(int n) {
    int i = 0, j, count = 0;
    vector<int> a(n, 0);  // 'a[i]' means the position of the queen in line 'i'
    while(i >= 0) {
        for(a[i]++; a[i] <= n; a[i]++)
            if(Check(a, i)) break;
        if(a[i] <= n)
            if(i == n-1) count++;
            else a[++i] = 0;
        else i--;      // backtrack
    }
    return count;
}

int main() {
    cout << solveNQueens(8);
    return 0;
}
