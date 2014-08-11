/*
  Given a binary tree, flatten it to a linked list in-place.

For example,
Given

         1
        / \
       2   5
      / \   \
     3   4   6
The flattened tree should look like:
   1
    \
     2
      \
       3
        \
         4
          \
           5
            \
             6
*/
#include <iostream>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
//passed@ first submit
//algorithm
class Solution {
 public:
  void flatten(TreeNode *root) {
    flat(root);
  }

  TreeNode* flat(TreeNode* root)
  {
    if(root == NULL) return NULL;
    if(root->left == NULL && root->right == NULL) return root;
    TreeNode* lastRight = flat(root->right);
    TreeNode* lastLeft;
    if(root->left != NULL)
    {
      lastLeft = flat(root->left);
      if(lastLeft != NULL) lastLeft->right = root->right;
      root->right = root->left;
      root->left = NULL;
    }
    return lastRight != NULL ? lastRight : lastLeft;
  }
};
