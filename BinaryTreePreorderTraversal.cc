/*
  Given a binary tree, return the preorder traversal of its nodes' values.

  For example:
  Given binary tree {1,#,2,3},
  1
  \
  2
  /
  3
  return [1,2,3].
  Solution: iteration
*/
#include <vector>
#include <deque>

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
 public:
  std::vector<int> preorderTraversal(TreeNode *root)
  {
    std::deque<TreeNode *> nodeList;
    std::vector<int> result;
    nodeList.push_back(root);
    while(!nodeList.empty())
    {
      TreeNode *curNode = nodeList.back();
      nodeList.pop_back();
      if(curNode == NULL)
        continue;
      result.push_back(curNode->val);
      nodeList.push_back(curNode->right);
      nodeList.push_back(curNode->left);
    }
    return result;
  }
};
