/*
  Given a binary tree, determine if it is height-balanced.

  For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.
*/
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  bool isBalanced(TreeNode *root)
  {
    return getBalanced(root) > -1;
  }

  int getBalanced(TreeNode *root)
  {
    if(root == NULL) return 1;
    int left = getBalanced(root->left);
    if(left == -1) return -1;
    int right = getBalanced(root->right);
    if(right == -1 || std::abs(left - right) > 1) return -1;
    return std::max(left, right) + 1;
  }
};
