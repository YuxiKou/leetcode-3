/*
  Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.
*/
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
 public:
  TreeNode *sortedListToBST(ListNode *head)
  {
    ListNode* curNode = head;
    int count = 0;
    while(curNode != NULL)
    {
      ++count;
      curNode = curNode->next;
    }
    return buildTree(head, 0, count - 1);
  }

  TreeNode *buildTree(ListNode* &node, int start, int end)
  {
    if(start > end) return NULL;
    int mid = start + (end - start) / 2;
    TreeNode* left = buildTree(node, start, mid - 1);
    TreeNode* head = new TreeNode(node->val);
    node = node->next;
    head->left = left;
    head->right = buildTree(node, mid + 1, end);
    return head;
  }
};
