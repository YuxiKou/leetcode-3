/*
  A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
  Return a deep copy of the list.
*/

/*
naive: create a copy of the list, and create a map<original, new>. this takes O(N) space
*/
#include <iostream>

struct RandomListNode {
  int label;
  RandomListNode *next, *random;
  RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
 public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    RandomListNode* curNode = head;
    while(curNode != NULL)
    {
      RandomListNode* nextNode = curNode->next;
      curNode->next = new RandomListNode(curNode->label);
      curNode->next->next = nextNode;
      curNode = nextNode;
    }
    RandomListNode* copyHead = NULL;
    curNode = head;
    RandomListNode* copyCurNode = NULL;
    while(curNode != NULL)
    {
      copyCurNode = curNode->next;
      if(copyHead == NULL)
      {
        copyHead = copyCurNode;
      }
      if(curNode->random != NULL)
      {
        copyCurNode->random = curNode->random->next;
      }
      curNode = copyCurNode->next;
    }

    curNode = head;
    copyCurNode = copyHead;
    while(curNode != NULL)
    {
      RandomListNode* next = copyCurNode->next;
      curNode->next = next;
      curNode = next;
      if(next != NULL)
      {
        copyCurNode->next = next->next;
        copyCurNode = next->next;
      }
    }
    return copyHead;
  }
};
