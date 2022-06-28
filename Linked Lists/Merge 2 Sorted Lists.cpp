#include <bits/stdc++.h>
#include "ListNode.h"
using namespace std;

ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
{
  if (list1 == NULL)
    return list2;
  if (list2 == NULL)
    return list1;

// head for the merged linked list
  ListNode *head = NULL;

  if (list1->val < list2->val) {
    head = list1;
    list1 = list1->next;
  }
  else
  {
    head = list2;
    list2 = list2->next;
  }

// maintain a tail for O(1) adding.
  ListNode *tail = head;

  while(list1 != NULL && list2 != NULL) {
    if (list1->val < list2->val) {
      // add the node to resultant list.
      tail->next = list1;

      // set tail to last node.
      tail = list1;

      list1 = list1->next;
    } else {
      // add the node to resultant list.
      tail->next = list2;

      // set tail to last node.
      tail = list2;

      list2 = list2->next;
    }
  }

  if (list1 != NULL) {
    tail->next = list1;
  }

  if (list2 != NULL) {
    tail->next = list2;
  }

  return head;
}
