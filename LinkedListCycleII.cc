/*
  Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

  Follow up:
  Can you solve it without using extra space?
*/
#include <iostream>
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
 public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *slowPtr = head;
    ListNode *fastPtr = head;
    while(true)
    {
      if(slowPtr == NULL || fastPtr == NULL) return NULL;
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next;
      if(fastPtr == NULL) return NULL;
      fastPtr = fastPtr->next;
      if(slowPtr == fastPtr) break;
    }
    slowPtr = head;
    while(slowPtr != fastPtr)
    {
      slowPtr = slowPtr->next;
      fastPtr = fastPtr->next;
    }
    return slowPtr;
  }
};
