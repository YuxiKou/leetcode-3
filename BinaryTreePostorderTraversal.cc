/*
  Given a binary tree, return the postorder traversal of its nodes' values.

  For example:
  Given binary tree {1,#,2,3},
  1
  \
  2
  /
  3
  return [3,2,1].
  Note: Recursive solution is trivial, could you do it iteratively?
*/
#include <vector>
#include <deque>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
 public:
  std::vector<int> postorderTraversal(TreeNode *root) {
    std::deque<TreeNode *> stack;
    std::vector<int> result;
    stack.push_back(root);
    while(!stack.empty())
    {
      TreeNode *curNode = stack.back();
      stack.pop_back();
      if(curNode == NULL) continue;
      if(curNode->right == NULL && curNode->left == NULL)
      {
        result.push_back(curNode->val);
      }
      else
      {
        stack.push_back(curNode);
        if(curNode->right != NULL)
        {
          stack.push_back(curNode->right);
          curNode->right = NULL;
        }
        if(curNode->left != NULL)
        {
          stack.push_back(curNode->left);
          curNode->left = NULL;
        }
      }
    }
    return result;
  }
};
