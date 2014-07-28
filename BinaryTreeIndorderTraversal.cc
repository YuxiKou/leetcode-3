/*
  Given a binary tree, return the inorder traversal of its nodes' values.

  For example:
  Given binary tree {1,#,2,3},
  1
  \
  2
  /
  3
  return [1,3,2].

  Note: Recursive solution is trivial, could you do it iteratively?
*/
#include <vector>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Solution {
 public:
  std::vector<int> inorderTraversal(TreeNode *root)
  {
    std::vector<int> result;
    inorderTraversalPrivate(root, result);
    return result;
  }
  void inorderTraversalPrivate(TreeNode *root, std::vector<int> &result)
  {
    if(root == NULL) return;
    inorderTraversalPrivate(root->left, result);
    result.push_back(root->val);
    inorderTraversalPrivate(root->right, result);
  }

};
