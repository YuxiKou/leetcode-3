/*
  Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

  For example,
  Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

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
  vector<TreeNode *> generateTrees(int n) {
    return *gen(1, n);
  }
  vector<TreeNode *> * gen(int start, int end)
  {
    vector<TreeNode *>* ret = new vector<TreeNode *>();
    if(start > end)
    {
      ret->push_back(NULL);
    }

    for(int i = start; i <= end; ++ i)
    {
      vector<TreeNode*>* left = gen(start, i - 1);
      vector<TreeNode*>* right = gen(i + 1, end);
      for(int j = 0; j < left->size(); ++ j)
      {
        for(int k = 0; k < right->size(); ++ k)
        {
          TreeNode* head = new TreeNode(i);
          head->left = (*left)[j];
          head->right = (*right)[k];
          ret->push_back(head);
        }
      }
    }
    return ret;
  }
};
