/*
  Given a linked list, determine if it has a cycle in it.

  Follow up:
  Can you solve it without using extra space?
*/
#include <iostream>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
 public:
  bool hasCycle(ListNode *head)
  {
    if(head == NULL) return false;
    ListNode *first = head;
    ListNode *second = head;
    while(second != NULL)
    {
      first = first->next;
      second = second->next;
      if(second != NULL)
      {
        second = second->next;
      }
      else
      {
        return false;
      }
      if(first == second)
      {
        return true;
      }
    }
    return false;
  }
};
