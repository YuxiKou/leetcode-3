/*
  Given a sorted linked list, delete all duplicates such that each element appear only once.

  For example,
  Given 1->1->2, return 1->2.
  Given 1->1->2->3->3, return 1->2->3.
*/

#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    ListNode *curStart = head;
    ListNode *curNode = curStart;
    /*
      1      2      2      2
             cs
                    cn
     */
    while(curStart != NULL)
    {
      curNode = curNode->next;
      if(curNode == NULL) return head;
      if(curNode->val == curStart->val)
        curStart->next = curNode->next;
      else
        curStart = curNode;
    }
    return head;
  }
};
