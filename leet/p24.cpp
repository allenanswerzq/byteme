#include<bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    ListNode *dummy = new ListNode(-1);
    dummy->next = head;
    ListNode *p = dummy;
    while (p && p->next && p->next->next) {
      ListNode *p1 = p;
      ListNode *p2 = p->next;
      ListNode *p3 = p->next->next;
      p1->next = p3;
      p2->next = p3->next;
      p3->next = p2;
      p = p->next->next;
    } 
    return dummy->next;
  }
};

void print(ListNode* root) {
  while (root) {
    cout << root->val;
    if (root->next) cout << "-->";
    root = root->next;
  }
  cout << endl;
}

void test() {
  ListNode *h = new ListNode(1);
  ListNode *p = h;
  for (int i = 2; i < 6; ++i) {
    p->next = new ListNode(i);
    p = p->next;
  }

  Solution go;
  print(h);
  print(go.swapPairs(h));
}

int main() {
  test();
  return 0;
}
