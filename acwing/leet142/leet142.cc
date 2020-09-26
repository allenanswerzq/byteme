/* created   : 2020-09-26 21:52:12
 * accepted  : 2020-09-26 21:52:12
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

// NOTE: for proof, see leet142.png
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    if (!head) return nullptr;
    if (!head->next) return nullptr;
    ListNode* root = new ListNode();
    root->next = head;
    auto slow = root;
    auto fast = root;
    bool cycle = false;
    while (slow && fast && fast->next) {
      if (slow != root && slow == fast) {
        cycle = true;
        break;
      }
      slow = slow->next;
      fast = fast->next->next;
    }
    if (cycle) {
      fast = root;
      while (fast && slow) {
        if (slow == fast) {
          return slow;
        }
        fast = fast->next;
        slow = slow->next;
      }
    }
    delete root;
    return nullptr;
  }
};

#define EXPECT_TRUE(a) assert(a)
#define EXPECT_FALSE(a) assert(!a)
#define EXPECT(a, b) assert(a == b)

void solve() {
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
