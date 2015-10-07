/*Copyright 2015 Edmund

Given two binary trees, write a function to check if they are equal or not. Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

#include <iostream>
using namespace std;

// Binary Tree
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == NULL && q == NULL) return true;
    if (p == NULL || q == NULL) return false;
    if (p->val == q->val)
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    return false;
}

int main() {
    /*  tree1          tree2
          1              1
        /   \          /   \
       2     3        2     3
     /   \              \
    4     5              5
    */
    TreeNode* tree1 = new TreeNode(1);
    tree1->left = new TreeNode(2);
    tree1->right = new TreeNode(3);
    tree1->left->left = new TreeNode(4);
    tree1->left->right = new TreeNode(5);

    TreeNode* tree2 = new TreeNode(1);
    tree2->left = new TreeNode(2);
    tree2->right = new TreeNode(3);
    tree2->left->right = new TreeNode(5);

    if(isSameTree(tree1, tree2)) cout << "tree1 and tree2 are same." << endl;
    else cout << "tree1 and tree2 are not same." << endl;
    return 0;
}
