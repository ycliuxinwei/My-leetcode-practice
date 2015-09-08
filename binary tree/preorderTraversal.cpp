#include <vector>
#include <stack>
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
Given a binary tree, return the preorder traversal of its nodes' values.

For example: Given binary tree {1,5,2,3,4},
     1
    / \
   5   2
      / \
     3   4
return [1,5,2,3,4].

Note: Recursive solution is trivial, could you do it iteratively?
*/

// recursive solution
void RecPreorder(TreeNode* node, vector<int>& a) {
	a.push_back(node->val);
	if(node->left!=NULL)
		RecPreorder(node->left,a);
	if(node->right!=NULL)
		RecPreorder(node->right,a);
}
vector<int> preorderTraversal(TreeNode* root) {
	vector<int> a;
	if(root!=NULL) RecPreorder(root, a);
	return a;
}

// iterative method
vector<int> preorderTraversal_Iter(TreeNode* root) {
	vector<int> a;
	stack<TreeNode*> b;
	b.push(root);
	while(!b.empty()) {
 		TreeNode* node = b.top(); b.pop();
        a.push_back(node->val);
		if(node->right) b.push(node->right);
		if(node->left) b.push(node->left);
	}
    return a;
}

int main() {
	TreeNode* tree = new TreeNode(1);
	tree->left = new TreeNode(5);
	tree->right = new TreeNode(2);
	tree->right->left = new TreeNode(3);
	tree->right->right = new TreeNode(4);
	vector<int> a = preorderTraversal(tree);
	printVector(a);
	vector<int> b = preorderTraversal_Iter(tree);
	printVector(b);
	return 0;
}