/*
  Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

  For example:
  Given binary tree {3,9,20,#,#,15,7},
      3
     / \
    9  20
      /  \
     15   7
  return its bottom-up level order traversal as:
  [
  [15,7],
  [9,20],
  [3]
  ]
  confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
*/
#include <vector>
#include <deque>

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
 public:
  std::vector<std::vector<int> > levelOrderBottom(TreeNode *root) {
    std::deque<std::vector<int> > tempResult;
    levelOrderBottomPrivate(root, 0, tempResult);
    std::vector<std::vector<int> > result;
    for(std::deque<std::vector<int> >::iterator it = tempResult.begin(); it != tempResult.end(); ++it)
    {
      result.push_back(*it);
    }
    return result;
  }
  void levelOrderBottomPrivate(TreeNode *root, int level, std::deque<std::vector<int> > &result)
  {
    if(root == NULL)
      return;
    int size = result.size();
    if(size <= level)
    {
      std::vector<int> oneRow;
      result.push_front(oneRow);
      ++size;
    }
    result[size - level - 1].push_back(root->val);
    if(root->left != NULL)
      levelOrderBottomPrivate(root->left, level + 1, result);
    if(root->right != NULL)
      levelOrderBottomPrivate(root->right, level + 1, result);
  }
};
