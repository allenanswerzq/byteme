#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

// TODO
class Solution {
public:
  ListNode* reverse(ListNode *head, int k) {
    if (!head || k <= 0) return head;
    ListNode *p = head;
    while (p && k--) {
      p = p->next;
    }

    if (k > 0) return head;

    ListNode *pre = p, *cur = head; 
    while (cur != p) {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  } 

  ListNode* reverseKGroup(ListNode* head, int k) {
    if (k <= 0) return head;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *p = dummy;
    while (p) {
      p->next = reverse(p->next, k);
      for (int i = 0; p && i < k; ++i) {
        p = p->next;
      }
    }
    return dummy->next;
  }
};

void print(ListNode *h) {
  while (h) {
    cout << h->val;
    h = h->next;
    if (h) cout << "-->";
  }
  cout << endl;
}

void test() {
  ListNode *h = new ListNode(1);
  ListNode *p = h;
  for (int i = 2; i < 8; ++i) {
    p->next = new ListNode(i);
    p = p->next;
  }

  Solution go;
  int n = 4;
  print(h);
  // print(go.reverse(h, 6));
  print(go.reverseKGroup(h, n));
}

int main() {
  test();
  return 0;
}
