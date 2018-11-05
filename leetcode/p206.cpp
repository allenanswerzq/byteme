#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Iterative approach
  ListNode* reverseList(ListNode* head) {
    if (!head) return nullptr;
    ListNode *pre = nullptr;
    ListNode *cur = head;
    while (cur)  {
      ListNode *next = cur->next;
      cur->next = pre;
      pre = cur;
      cur = next;
    }
    return pre;
  }

  // Recursive
  ListNode* reverseList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *root = reverseList(head->next);
    // Note: hard to understand at first looking
    head->next->next = head;
    head->next = nullptr;
    return root;
  }
};

int main() {
  return 0;
}
