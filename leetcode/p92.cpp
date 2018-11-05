#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    if (!head) return nullptr;
    ListNode *dummy = new ListNode(0);
    dummy->next = head;
    int k = 0;
    ListNode* p = dummy;
    ListNode* start, *next, *prev = nullptr;
    while (p) {
      if (k == m-1) start = p;
      else if (k == m) {
        ListNode *end = p;
        while (k <= n && p) {
          next = p->next;
          p->next = prev;
          prev = p;
          p = next;
          k++;
        }
        end->next = next;
        start->next = prev;
        return dummy->next;
      }
      p = p->next;
      k++;
    }
    return dummy->next;
  }  
};

int main() {
  return 0;
}
