#include<bits/stdc++.h>using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
  ListNode* removeNthFromEnd(ListNode* head, int kk) {
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    ListNode *p1 = dummy;
    ListNode *p2 = dummy;

    while (kk--) {
      p2 = p2->next;
      if (!p2) return nullptr;
    }

    while (p2 && p2->next) {
      p1 = p1->next;
      p2 = p2->next;
    }

    p1->next = p1->next->next;
    return dummy->next;
  }
};

void test() {
  Solution go;
  ListNode *root = new ListNode(1);
  ListNode *p = root;
  for (int i=2; i <= 5; ++i) {
    p->next = new ListNode(i);
    p = p -> next;
  }
  root = go.removeNthFromEnd(root, 1);
  while (root) {
    cout << root->val << " --> ";
    root = root->next;
  }
}

int main() {
  test();
  return 0;
}
