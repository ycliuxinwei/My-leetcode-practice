/* Copyright 2015 Edmund Liu

Given a binary tree and a sum, determine if the tree has a root-to-leaf path such that adding up all the values along the path equals the given sum.

For example: Given the below binary tree and sum = 22,

       5
      / \
     4   8
    /   / \
   11  13  4
  /  \      \
 7    2      1

return true, as there exist a root-to-leaf path 5->4->11->2 which sum is 22.

*/
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

// Binary Tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// print the vector
void printVector(const vector<int>& a) {
    cout << "[";
    vector<int>::const_iterator it;
    for (it = a.begin(); it != a.end()-1; it++)
        cout << *it << " ";
    cout << *it << "]" << endl;
}

void traversePath(TreeNode* root, vector<int>& b) {
    int sum = b.back();
	if (root->left != NULL) {
		b.back() = sum + root->left->val;
		traversePath(root->left, b);
	}
	if (root->left != NULL && root->right != NULL) b.push_back(sum);
	if (root->right != NULL) {
		b.back() = sum + root->right->val;
		traversePath(root->right, b);
	}
}

bool hasPathSum1(TreeNode* root, int sum) {
    if (root == NULL) return false;
    vector<int> a;
    a.push_back(root->val);
    traversePath(root, a);
    printVector(a);
    return find(a.begin(), a.end(), sum) != a.end();
}

bool hasPathSum2(TreeNode* root, int sum) {
    if(root == NULL) return false;
    if(root->left == NULL && root->right == NULL && sum - root->val == 0) return true;
    return hasPathSum2(root->left, sum - root->val) || hasPathSum2(root->right, sum - root->val);
}

int main() {
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(4);
    root->right = new TreeNode(8);
    root->left->left = new TreeNode(11);
    root->right->left = new TreeNode(13);
    root->right->right = new TreeNode(4);
    root->left->left->left = new TreeNode(7);
    root->left->left->right = new TreeNode(2);
    root->right->right->right = new TreeNode(1);

    cout << hasPathSum2(root, 22);

    return 0;
}
