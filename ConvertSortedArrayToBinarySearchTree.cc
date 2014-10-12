/*
  Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
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
  TreeNode *sortedArrayToBST(std::vector<int> &num)
  {
      return sortedArrayToBSTPrivate(num, 0, num.size() - 1);
  }

  TreeNode *sortedArrayToBSTPrivate(std::vector<int> &num, int start, int end)
  {
    if(start > end) return NULL;
    int mid = start + (end - start) / 2;
    TreeNode *root = new TreeNode(num[mid]);
    root->left = sortedArrayToBSTPrivate(num, start, mid - 1);
    root->right = sortedArrayToBSTPrivate(num, mid + 1, end);
    return root;
  }
};
