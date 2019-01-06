#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  TreeNode* build(ListNode* head, ListNode* tail) {
    ListNode *p = head;
    ListNode *mid = head;
    if (head == tail) return NULL;
    while (p != tail && p->next != tail) {
      // p is faster than mid one step
      // It means mid arrives median of List when p reach tail.
      p = p->next->next;
      mid = mid->next;
    }

    TreeNode* root = new TreeNode(mid->val);
    root->left = build(head, mid);
    root->right = build(mid->next, tail);
    return root;

  }

  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    return build(head, nullptr);
  }
};

int main() {
  return 0;
}
