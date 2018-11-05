#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  void reorderList(ListNode* head) {
    ListNode *p, *q;
    p = q = head;
    while (q->next && q->next->next) {
      q = q->next->next;
      p = p->next;
    }    

    ListNode *pre = nullptr;
    q = p->next;
    p->next = nullptr;
    while (q) {
      ListNode *next = q->next;
      q->next = pre;
      pre = q;
      q = next;
    }

    q = head;
    p = pre;
    while (p) {
      ListNode *x = q->next;
      ListNode *y = p->next;
      q->next = p;
      p->next = x;
      q = x;
      p = y;
    }
  }
};

int main() {
  return 0;
}
