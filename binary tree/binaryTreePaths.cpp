#include <vector>
#include <string>
#include <strstream>
#include <iostream>
using namespace std;

// Binary Tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// int to string (has warnings)
string myto_string(int a) {
	strstream ss;
	string s;
	ss << a; ss >> s;
	return s;
}

// print the vector
template <typename T>
void printVector(T& a) {
	cout << "[";
	typename T::iterator it;
	for (it=a.begin(); it!=a.end()-1; it++)
		cout << *it << " ";
	cout << *it << "]" << endl;
}

void Paths(TreeNode* root, vector<string>& b) {
	string str = b.back();
	if (root->left != NULL) {
		b.back() = str + "->" + myto_string(root->left->val); // ('to_string' may not be supported by g++)
		Paths(root->left, b);
	}
	if (root->left != NULL && root->right != NULL) b.push_back(str);
	if (root->right != NULL) {
		b.back() = str + "->" + myto_string(root->right->val);
		Paths(root->right, b);
	}
}

/*
Given a binary tree, return all root-to-leaf paths.

For example, given the following binary tree:

      1
    /  \
   2    3
 /  \
4    5

All root-to-leaf paths are: ["1->2->4", "1->2->5", "1->3"].
*/
vector<string> binaryTreePaths(TreeNode* root) {
	vector<string> a;
	if (root == NULL) return a;
	a.push_back(myto_string(root->val));
	Paths(root, a);
	return a;
}

int main() {

	TreeNode* root = new TreeNode(1);
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);
	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);
	vector<string> paths = binaryTreePaths(root);
	printVector(paths);
	
	return 0;
}