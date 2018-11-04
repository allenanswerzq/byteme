#include<bits/stdc++.h>
using namespace std;

class Solution {
  // Carefully read the statement for problems.
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return nullptr;
    int n = 0;
    ListNode *p = head;
    while (p) {
      p = p->next;
      n++;
    }
    k = k % n;

    ListNode *p, *q;
    p = head;
    q = head;
    while (k-- > 0 && q) q = q->next;
    if (!q && k == 0) return head;
    
    while (q->next) {
      p = p->next;
      q = q->next;
    }

    q->next = head;
    q = p->next;
    p->next = nullptr;
    return q;
  }
};

int main() {
  return 0;
}
