/* created   : 2022-05-02 14:02:32
 * accepted  : 2022-05-02 14:06:52
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

class Solution {
public:
  ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    auto p = &head;
    auto q = &head->next;
    while (*p && *q) {
      // cout << (*p)->val << " " << (*q)->val << endl;
      auto t = *p;
      *p = (*q)->next;
      (*q)->next = t;
      swap(*p, *q);
      if (t) p = &t->next;
      else break;
      if (*p) q = &(*p)->next;
      else break;
    }
    return head;
  }
};
