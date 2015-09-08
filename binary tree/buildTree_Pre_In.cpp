#include <vector>
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
Given preorder and inorder traversal of a tree, construct the binary tree.
       1
     /   \
   2      3
 /  \    /
4    5  6
     \
	  7
Note: You may assume that duplicates do not exist in the tree.
*/
void build(TreeNode*& root, vector<int>& preorder, vector<int>& inorder, int preStart, int preEnd, int inStart, int inEnd) {
	root = new TreeNode(preorder[preStart]);
	int i;
	for(i = inStart; i <= inEnd; i++)
		if(preorder[preStart] == inorder[i]) break;
	if(i-inStart>0) build(root->left, preorder, inorder, preStart+1, i-inStart+preStart, inStart, i-1);
	if(i-inEnd<0) build(root->right, preorder, inorder, i-inStart+preStart+1, preEnd, i+1, inEnd);
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int n = preorder.size();
	TreeNode* root = NULL;
	if(n > 0) build(root, preorder, inorder, 0, n-1, 0, n-1);
	return root;
}

int main() {
	int a[] = {1,2,4,5,7,3,6};
	vector<int> pre(a, a+7);
	int b[] = {4,2,5,7,1,6,3};
	vector<int> in(a, a+7);
	TreeNode* tree = buildTree(pre, in);
	return 0;
}