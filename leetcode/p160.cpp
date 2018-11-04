#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
  int len(ListNode *head) {
    if (!head) return 0;
    return 1 + len(head->next); 
  }

  ListNode *getIntersectionNode(ListNode *pa, ListNode *pb) {
    int la = len(pa);
    int lb = len(pb);
    if (la == 0 || lb == 0) return nullptr;
    ListNode *p = la > lb ? pa : pb;
    ListNode *q = la > lb ? pb : pa; 
    int x = abs(la - lb);
    while (x-- > 0) {
      p = p->next;
    }
    while (p && q) {
      if (p == q) return p;
      p = p->next;
      q = q->next;
    }
    return nullptr;
  }
};

int main() {
  return 0;
}
