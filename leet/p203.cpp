#include<bits/stdc++.h>
using namespace std;

// Accepted
ListNode* removeElements(ListNode* head, int val) {
  ListNode *dummy = new ListNode(0);  
  ListNode *p = dummy;
  ListNode *q = head;
  while (q) {
  if (q->val != val) {
    p->next = q;
    p = p->next;
    q = q->next;
    p->next = nullptr;
  } else {
    ListNode *t = q;
    q=q->next;
    delete t;
  }
  }
  return dummy->next;
}

int main(int argc, char** argv) {
  return 0;
}
