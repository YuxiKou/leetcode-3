/*
  Given a linked list, swap every two adjacent nodes and return its head.

  For example,
  Given 1->2->3->4, you should return the list as 2->1->4->3.

  Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.
*/
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *swapPairs(ListNode *head)
  {
    if(head == NULL || head->next == NULL) return head;
    ListNode *newHead = new ListNode(0);
    newHead->next = head;
    ListNode *curNode1;
    ListNode *curNode2;
    head = newHead;
    while(true)
    {
      if(head == NULL) break;
      curNode1 = head->next;
      if(curNode1 == NULL) break;
      curNode2 = curNode1->next;
      if(curNode2 == NULL) break;
      curNode1->next = curNode2->next;
      head->next = curNode2;
      curNode2->next = curNode1;
      head = curNode1;
    }
    return newHead->next;
  }
};
