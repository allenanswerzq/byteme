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
   if (!head) return head;
    auto p = &head;
    auto q = &head->next;
    while (*p && *q) {
      //     t
      // --> x --> y --> z
      //  p     q
      auto t = *p;
      *p = (*q)->next;
      (*q)->next = t;
      swap(*p, *q);
      p = &t->next;
      if (*p) q = &(*p)->next;
    }
    return head;
  }
};
