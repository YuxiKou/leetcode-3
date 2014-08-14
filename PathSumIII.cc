/*
  Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.

  For example:
  Given the below binary tree and sum = 22,
  5
  / \
  4   8
  /   / \
  11  13  4
  /  \    / \
  7    2  5   1
  return
  [
  [5,4,11,2],
  [5,8,4,5]
  ]
*/


#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<vector<int> > pathSum(TreeNode *root, int sum) {
    vector<int> curResult;
    vector<vector<int> > result;
    pathSumPrivate(root, sum, curResult, result);
    return result;
  }
  void pathSumPrivate(TreeNode* root, int sum, vector<int> &curResult, vector<vector<int> > &result)
  {
    if(root == NULL) return;
    if(root->left == NULL && root->right == NULL)
    {
      if(root->val == sum)
      {
        curResult.push_back(root->val);
        result.push_back(curResult);
        curResult.pop_back();
      }
      return;
    }

    curResult.push_back(root->val);
    if(root->left != NULL) pathSumPrivate(root->left, sum - root->val, curResult, result);
    if(root->right != NULL) pathSumPrivate(root->right, sum - root->val, curResult, result);
    curResult.pop_back();
  }
};
