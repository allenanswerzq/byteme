#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode* partition(ListNode* head, int val) {
    if (!head) return NULL;
    ListNode *h = head;
    ListNode *lt, *p;
    lt = p = new ListNode(0);
    ListNode *gt, *q;
    gt = q = new ListNode(0);
    while (h) {
      ListNode *t = h->next;
      if (h->val < val) {
        p->next = h;
        p = p->next;
        p->next = NULL;
      } else {
        q->next = h;
        q = q->next;
        q->next = NULL;
      }
      h = t;
    }
    p->next = gt->next;
    return lt->next;
  }
};

int main() {
  return 0;
}
