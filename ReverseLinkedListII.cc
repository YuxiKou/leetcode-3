/*
  Reverse a linked list from position m to n. Do it in-place and in one-pass.

  For example:
  Given 1->2->3->4->5->NULL, m = 2 and n = 4,

  return 1->4->3->2->5->NULL.

  Note:
  Given m, n satisfy the following condition:
  1 ≤ m ≤ n ≤ length of list.
*/

/*
  find the mth node
  start reversing length n - m
  note:

  reverse exit condition:
  if(head == NULL || length <= 1) return head;
*/
#include <stack>

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    ListNode *newHead = new ListNode(0);
    newHead->next = head;
    ListNode *curNode = newHead;
    /*
      m = 2, n = 4
      0       1       2       3       4       5
              cur
     */
    for(int i = 0; i < m - 1; ++i)
    {
      curNode = curNode->next;
    }

    curNode->next = reverse(curNode->next, n - m + 1);
    return newHead->next;
  }
  //algorithm to reverse linked list with certain length
  ListNode *reverse(ListNode *head, int length)
  {
    if(head == NULL || length <= 1) return head;
    ListNode *lastNode = head->next;
    ListNode *newHead = reverse(head->next, length - 1);
    head->next = lastNode->next;
    lastNode->next = head;
    return newHead;
  }
};
