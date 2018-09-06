#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode* merge(ListNode *x, ListNode *y) {
    ListNode *dummy = new ListNode(0);
    ListNode *p = dummy;
    while (x || y) {
      ListNode *t = new ListNode(INT_MAX);
      if (x && x->val < t->val) t = x;
      if (y && y->val < t->val) t = y;
      if (t == x) x = x->next;
      else y = y->next;
      p->next = t;
      p = p->next;
    }
    return dummy->next;
  }

  ListNode* sortList(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) return head;

    ListNode *fast, *slow;
    fast = slow = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *last = slow->next;
    slow->next = nullptr;
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(last);
    return merge(l1, l2);
  }
};

int main(int argc, char** argv) {
  return 0;
}
