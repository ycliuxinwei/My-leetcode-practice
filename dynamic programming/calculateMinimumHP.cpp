#include <vector>
#include <iostream>
using namespace std;

// the max number between a and b
template <typename T>
T Max(T a, T b) { return a>b? a:b; }

// the min number between a and b
template <typename T>
T Min(T a, T b) { return a<b? a:b; }

// print the matrix
void printMatrix(const vector<vector<int> >& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	cout << "[>>>>>>>>>>" << endl;
	for (int i=0; i<n; i++) {
		vector<int>::const_iterator it;
		for (it=matrix[i].begin(); it!=matrix[i].end()-1; it++)
			cout << *it << "\t";
		cout << *it << endl;
	}
	cout << "<<<<<<<<<<]" << endl;
}

/*
The demons had captured the princess (P) and imprisoned her in the bottom-right corner of a dungeon. The dungeon consists of M x N rooms laid out in a 2D grid. Our valiant knight (K) was initially positioned in the top-left room and must fight his way through the dungeon to rescue the princess.

The knight has an initial health point represented by a positive integer. If at any point his health point drops to 0 or below, he dies immediately.

Some of the rooms are guarded by demons, so the knight loses health (negative integers) upon entering these rooms; other rooms are either empty (0's) or contain magic orbs that increase the knight's health (positive integers).

In order to reach the princess as quickly as possible, the knight decides to move only rightward or downward in each step.

Write a function to determine the knight's minimum initial health so that he is able to rescue the princess.

For example, given the dungeon below, the initial health of the knight must be at least 7 if he follows the optimal path RIGHT-> RIGHT -> DOWN -> DOWN.

|-------------------------------|
|  -2 (K)  |    -3   |    3     |
|-------------------------------|
|    -5    |   -10   |    1     |
|-------------------------------|
|    10    |   30    |  -5 (P)  |
|-------------------------------|

Notes:

The knight's health has no upper bound.

Any room can contain threats or power-ups, even the first room the knight enters and the bottom-right room where the princess is imprisoned.
*/
int calculateMinimumHP(vector<vector<int> >& dungeon) {
	int m = dungeon.size();
	int n = dungeon[0].size();
	vector<vector<int> > HP(m,vector<int>(n));
	// HP[i][j] = max(1, min(HP[i+1][j], HP[i][j+1])-dungeon[i][j])
	HP[m-1][n-1] = max(1, 1-dungeon[m-1][n-1]);
	for(int i = m-2; i >= 0; i--)
		HP[i][n-1] = max(1, HP[i+1][n-1]-dungeon[i][n-1]);
	for(int i = n-2; i >= 0; i--)
		HP[m-1][i] = max(1, HP[m-1][i+1]-dungeon[m-1][i]);
	for(int i = m-2; i >= 0; i--)
		for(int j = n-2; j >= 0; j--)
			HP[i][j] = max(1, min(HP[i][j+1], HP[i+1][j])-dungeon[i][j]);
//	printMatrix(HP);
	return HP[0][0];
}

int main() {
	vector<vector<int> > matrix(3);
	matrix[0].push_back(-2); matrix[0].push_back(-3); matrix[0].push_back(3);
	matrix[1].push_back(-5); matrix[1].push_back(-10); matrix[1].push_back(1);
	matrix[2].push_back(10); matrix[2].push_back(30); matrix[2].push_back(-5);
	printMatrix(matrix);
	cout << "the initial health point = " <<calculateMinimumHP(matrix);
	return 0;
}