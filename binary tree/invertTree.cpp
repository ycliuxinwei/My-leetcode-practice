/* Copyright 2015 Edmund Liu

Invert a binary tree.

     4
   /   \
  2     7
 / \   / \
1   3 6   9

to

     4
   /   \
  7     2
 / \   / \
9   6 3   1

*/
#include <vector>
#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

// Binary Tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    explicit TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// print the binary tree vertically
void PrintBinTreeVert(TreeNode* root, int nLayer) {  
    if (root == NULL) return;
    PrintBinTreeVert(root->right, nLayer + 5);
    for (int i = 0; i < nLayer; i++)
        cout << " ";
    cout << root->val << endl;
    PrintBinTreeVert(root->left, nLayer + 5);
}

// print the vector
void printVector(const vector<int>& a) {
    cout << "[";
    vector<int>::const_iterator it;
    for (it = a.begin(); it != a.end()-1; it++)
        cout << *it << " ";
    cout << *it << "]" << endl;
}

void invert(TreeNode* root) {
    if (root == NULL) return;
    swap(root->left, root->right);
    invert(root->left);
    invert(root->right);
}

TreeNode* invertTree(TreeNode* root) {
    invert(root);
    return root;
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
    
    PrintBinTreeVert(root, 0);
    TreeNode* invroot = invertTree(root);
    
    PrintBinTreeVert(invroot, 0);
    return 0;
}
