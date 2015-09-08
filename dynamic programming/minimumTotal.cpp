#include <iostream>
#include <vector>
using namespace std;

template <typename T>
T Min(T a, T b) { return a<b? a:b; }

void printMatrix(vector<vector<int> >& matrix) {
	int n = matrix.size();
	cout << "[>" << endl;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < matrix[i].size()-1; j++)
			cout << matrix[i][j] << "\t";
		cout << matrix[i][matrix[i].size()-1] << endl;
	}
	cout << "<<<<<<<<<<<<<<<<<<<<<<<<<]" << endl;
}

/* create triangle */
vector<vector<int> > createTria() {
	vector<vector<int> > a;
	vector<int> b;
	for(int i = 0; i < 4; i++) {
		b.clear();
		for(int j = 0; j < i+1; j++)
			b.push_back(i*(i+1)/2+j+2);
		a.push_back(b);
	}
	a[2][0] = 6; a[2][1] = 5;
	a[3][0] = 4; a[3][1] = 1; a[3][2] = 8; a[3][3] = 3;
	return a;
}

/*
Given a triangle, find the minimum path sum from top to bottom. Each step you may move to adjacent numbers on the row below.

For example, given the following triangle
[
   [2],
  [3,4],
 [6,5,7],
[4,1,8,3]
]

The minimum path sum from top to bottom is 11 (i.e., 2 + 3 + 5 + 1 = 11).

Note: Bonus point if you are able to do this using only O(n) extra space, where n is the total number of rows in the triangle.
*/
int minimumTotal(vector<vector<int> >& triangle) {
	int m = triangle.size()-2;
	for(int i = m; i >= 0; i--)
		for(int j = 0; j <= i; j++)
			triangle[i][j] += Min(triangle[i+1][j], triangle[i+1][j+1]);
	return triangle[0][0];
}

int main() {
	vector<vector<int> > a = createTria(); // create triangle
	printMatrix(a);
	cout << minimumTotal(a);
	return 0;
}