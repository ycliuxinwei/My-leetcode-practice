#include <vector>
#include <stack>
#include <algorithm>
#include <iostream>
using namespace std;

// Binary Tree
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// print the vector
void printVector(vector<int>& a) {
	cout << "[";
	vector<int>::iterator it;
	for (it=a.begin(); it!=a.end()-1; it++)
		cout << *it << " ";
	cout << *it << "]" << endl;
}

/*
Given a binary tree, return the postorder traversal of its nodes' values.

For example: Given binary tree {1,5,2,3,4},
     1
    / \
   5   2
      / \
     3   4
return [5,3,4,2,1].

Note: Recursive solution is trivial, could you do it iteratively?
*/

// recursive solution
void RecPostorder(TreeNode* node, vector<int>& a) {
	if(node->left) RecPostorder(node->left, a);
	if(node->right) RecPostorder(node->right, a);
	a.push_back(node->val);
}
vector<int> postorderTraversal(TreeNode* root) {
	vector<int> a;
	if(root) RecPostorder(root, a);
	return a;
}

// iterative solution
vector<int> postorderTraversal_Iter(TreeNode* root) {
	vector<int> a;
	stack<TreeNode*> b;
	b.push(root);
	while(!b.empty()) {
 		TreeNode* node = b.top(); b.pop();
        a.push_back(node->val);
		if(node->left) b.push(node->left);
		if(node->right) b.push(node->right);
	}
	reverse(a.begin(), a.end());
    return a;
}

int main() {
	TreeNode* tree = new TreeNode(1);
	tree->left = new TreeNode(5);
	tree->right = new TreeNode(2);
	tree->right->left = new TreeNode(3);
	tree->right->right = new TreeNode(4);
	vector<int> a = postorderTraversal(tree);
	printVector(a);
	vector<int> b = postorderTraversal_Iter(tree);
	printVector(b);
	return 0;
}