/*
  Given a binary tree

  struct TreeLinkNode {
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode *next;
  }
  Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

  Initially, all next pointers are set to NULL.

  Note:

  You may only use constant extra space.
  You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
  For example,
  Given the following perfect binary tree,
  1
  /  \
  2    3
  / \  / \
  4  5  6  7
  After calling your function, the tree should look like:
  1 -> NULL
  /  \
  2 -> 3 -> NULL
  / \  / \
  4->5->6->7 -> NULL
*/
#include <deque>

struct TreeLinkNode {
  int val;
  TreeLinkNode *left, *right, *next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
 public:
  void connect(TreeLinkNode *root)
  {
    std::deque<TreeLinkNode *> nodes;
    TreeLinkNode *prevNode = NULL;
    int levelCounter = 1;
    nodes.push_back(root);
    while(!nodes.empty())
    {
      TreeLinkNode *curNode = nodes.front();
      nodes.pop_front();
      if(curNode == NULL) continue;
      nodes.push_back(curNode->left);
      nodes.push_back(curNode->right);
      if(prevNode != NULL) prevNode->next = curNode;
      //the use of level counter!!!
      --levelCounter;
      if(levelCounter == 0)
      {
        levelCounter = nodes.size();
        prevNode = NULL;
        curNode->next = NULL;
      }
      else
      {
        prevNode = curNode;
      }
    }
  }
};
