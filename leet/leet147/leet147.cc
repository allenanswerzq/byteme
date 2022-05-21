/* created   : 2022-05-21 10:57:18
 * accepted  : 2022-05-21 10:58:06
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

class Solution {
public:
  ListNode* insertionSortList(ListNode* head) {
    if (!head) return head;
    ListNode* root = new ListNode();
    auto p = &head;
    while (*p) {
      auto pos = *p;
      *p = (*p)->next;
      auto t = &root->next;
      while (*t && pos->val > (*t)->val) {
        t = &(*t)->next;
      }
      pos->next = *t;
      *t = pos;
    }
    return root->next;
  }
};
