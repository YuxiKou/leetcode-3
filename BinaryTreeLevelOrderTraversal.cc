/*
  Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).

  For example:
  Given binary tree {3,9,20,#,#,15,7},
     3
    / \
   9  20
     /  \
    15   7
  return its level order traversal as:
  [
  [3],
  [9,20],
  [15,7]
  ]
  confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
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
  std::vector<std::vector<int> > levelOrder(TreeNode *root) {
    std::deque<TreeNode *> queue;
    std::vector<std::vector<int> > result;
    std::vector<int> curRow;
    if(root == NULL)
      return result;
    queue.push_back(root);
    int count = 1;
    while(!queue.empty())
    {
      TreeNode *curNode = queue.front();
      queue.pop_front();
      curRow.push_back(curNode->val);
      if(curNode->left != NULL) queue.push_back(curNode->left);
      if(curNode->right != NULL) queue.push_back(curNode->right);
      if(--count == 0)
      {
        count = queue.size();
        result.push_back(curRow);
        curRow.clear();
      }
    }
    return result;
  }
};
