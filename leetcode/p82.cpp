#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return NULL;
    ListNode *dummy = new ListNode(0);
    ListNode *p = dummy;
    ListNode *q = head;
    while (q && q->next) {
      if (q->val != q->next->val) {
        ListNode *t = q->next;
        p->next = q;
        p = p->next;
        p->next = NULL;
        q = t;
      } else {
        while(q && q->next && q->val == q->next->val) {
          q = q->next;
        }
        q = q->next;
      }
    }
    if (q) {
      p->next = q;
    }
    return dummy->next;
  }
};

int main() {
  return 0;
}
