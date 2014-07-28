/*
  Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
*/
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(0);
    ListNode *last = head;
    while(l1 != NULL && l2 != NULL)
    {
      if(l1->val < l2->val)
      {
        last->next = l1;
        l1 = l1->next;
        last = last->next;
        last->next = NULL;
      }
      else
      {
        last->next = l2;
        l2 = l2->next;
        last = last->next;
        last->next = NULL;
      }
    }
    if(l1 != NULL) last->next = l1;
    if(l2 != NULL) last->next = l2;
    return head->next;
  }
};
