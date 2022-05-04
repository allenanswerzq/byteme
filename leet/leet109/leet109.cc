/* created   : 2022-05-04 16:42:17
 * accepted  : 2022-05-04 16:42:17
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) return nullptr;
    if (!head->next) return new TreeNode(head->val);
    auto slow = &head; // NOTE: the ** pointer here
    auto fast = head;
    while (fast->next && fast->next->next) {
      slow = &(*slow)->next;
      fast = fast->next->next;
    }
    int val = (*slow)->val;
    TreeNode* root = new TreeNode(val);
    root->right = sortedListToBST((*slow)->next);
    (*slow) = nullptr;
    root->left = sortedListToBST(head);
    return root;
  }
};
