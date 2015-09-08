#include <iostream>
#include <vector>
using namespace std;

void printVector(vector<int>& a) {
	cout << "[";
	vector<int>::iterator it;
	for (it=a.begin(); it!=a.end()-1; it++)
		cout << *it << " ";
	cout << *it << "]" << endl;
}

void printMatrix(vector<vector<int> >& matrix) {
	int n = matrix.size();
	int m = matrix[0].size();
	cout << "[>>>>>>>>>>" << endl;
	for (int i=0; i<n; i++) {
		cout << "[";
		for (int j=0; j<m-1; j++)
			cout << matrix[i][j] << "\t";
		cout << matrix[i][m-1] << "]" << endl;
	}
	cout << "<<<<<<<<<<]" << endl;
}

/*
Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.

For example, Given the following matrix:
[
 [ 1, 2, 3 ],
 [ 4, 5, 6 ],
 [ 7, 8, 9 ]
]

You should return [1,2,3,6,9,8,7,4,5].
*/
vector<int> spiralOrder(vector<vector<int> >& matrix) {
    vector<int> b;
    if (matrix.empty()) return b;
	int n = matrix.size();
	int m = matrix[0].size();
	vector<int> a(m*n);
	int beginx = 0, beginy = 0, total = 0;
	int endx = m-1, endy = n-1;
    for ( ; ; ) {
		for (int j = beginx; j <= endx; ++j) a[total++] = matrix[beginy][j];
		if (++beginy > endy) break;
		
        for (int i = beginy; i <= endy; ++i) a[total++] = matrix[i][endx];
		if (beginx > --endx) break;
		
        for (int j = endx; j >= beginx; --j) a[total++] = matrix[endy][j];
		if (beginy > --endy) break;
		
        for (int i = endy; i >= beginy; --i) a[total++] = matrix[i][beginx];
		if (++beginx > endx) break;
    }
    return a;
}

/*
生成矩阵：n行 * m列
*/
vector<vector<int> > generateMatrix(int n, int m) {
	vector<vector<int> > matrix;
	vector<int> line(m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			line[j] = m*i + j + 1;
		matrix.push_back(line);
	}
	return matrix;
}

int main() {
	int n, m;
	cout << "rows: "; cin >> n;
	cout << "columns: "; cin >> m;
	vector<vector<int> > matrix = generateMatrix(n,m);
	printMatrix(matrix);
	
	vector <int> a = spiralOrder(matrix);
	printVector(a);
	return 0;
}