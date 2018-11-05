#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  ListNode* insertionSortList(ListNode* head) {
    if (!head) return nullptr;

    ListNode *dummy = new ListNode(INT_MIN);
    ListNode *cur = head;
    while (cur) {
      ListNode *next = cur->next;
      ListNode *pre = dummy;
      while (pre->next != nullptr && pre->next->val < cur->val)
        pre = pre->next; 
      cur->next = pre->next;
      pre->next = cur;
      cur = next;
    }
    return dummy->next;
  }
};

int main() {
  return 0;
}
