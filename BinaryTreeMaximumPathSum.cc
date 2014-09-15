/*
  Given a binary tree, find the maximum path sum.

  The path may start and end at any node in the tree.

  For example:
  Given the below binary tree,

  1
  / \
  2   3
  Return 6.
*/

/*
  recursion, need pass two values:
  sum: the maximum from sub path. the max between root->val, root->val + leftMax, root->val + rightMax
  max: the max between sum and root->val + leftMax + rightMax
 */

#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int maxPathSum(TreeNode *root) {
    int max = INT_MIN;
    maxSum(root, max);
    return max;
  }

  int maxSum(TreeNode *root, int &max) {
    if(root == NULL) return 0;
    int leftMax = maxSum(root->left, max);
    int rightMax = maxSum(root->right, max);
    int sum = std::max(root->val, std::max(leftMax, rightMax) + root->val);
    max = std::max(sum, std::max(max, leftMax + root->val + rightMax));
    return sum;
  }
};
