#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

ListNode* mergeTwoLists(ListNode* p1, ListNode* p2) {
  ListNode* dummy = new ListNode(-1);
  ListNode* p = dummy;
  while (p1 || p2) {
    if (p1 && p2) {
      if (p1->val <= p2->val) {
        p->next = p1; 
        p1 = p1->next;
      } else {
        p->next = p2;
        p2 = p2->next;
      }
    } else if (p1) {
      p->next = p1;
      p1 = p1->next;
    } else {
      p->next = p2;
      p2 = p2->next;
    }
    p = p->next;
  }
  return dummy->next;
}

class Solution {
public:
  ListNode* mergeKLists(vector<ListNode*>& aa) {
    int n = aa.size();
    if (n == 0) return nullptr;
    if (n == 1) return aa[0];

    ListNode *ret = nullptr;
    vector<ListNode*> left;
    vector<ListNode*> right;

    for (int i = 0; i < n / 2; ++i) 
      left.push_back(aa[i]);

    for (int i = n / 2; i < n; ++i) 
      right.push_back(aa[i]);

    ListNode *p1 = mergeKLists(left);
    ListNode *p2 = mergeKLists(right);
    ret = mergeTwoLists(p1, p2);
    return ret;
  }
};

void print(ListNode *head) {
  while (head) {
    cout << head->val << " ";
    head = head->next;
  }
}

void test() {
  ListNode *a = new ListNode(1);
  a->next = new ListNode(4);
  a->next->next = new ListNode(5);

  ListNode *b = new ListNode(2);
  b->next = new ListNode(6);
  b->next->next = new ListNode(8);
  
  ListNode *c = new ListNode(0);
  c->next = new ListNode(3);
  c->next->next = new ListNode(10);

  vector<ListNode*> list;
  list.push_back(a);
  list.push_back(b);
  list.push_back(c);

  Solution go;
  print(go.mergeKLists(list));
}

int main() {
  test();
  return 0;
}
