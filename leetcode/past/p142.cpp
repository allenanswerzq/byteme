#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  // Use extra space, but it worked
  ListNode *detectCycle(ListNode *head) {
    if (!head) return nullptr;
    unordered_map<ListNode*, bool> mp;
    ListNode *p = head;
    while (p) {
      if (mp.count(p)) 
        return p;
      else { 
        mp[p] = true; 
        p = p->next;
      }
    }    
    return nullptr;
  }

  // reference: 
  // https://en.wikipedia.org/wiki/Cycle_detection#Floyd.27s_Tortoise_and_Hare
  // Only constant sapce
  ListNode *detectCycle(ListNode *head) { 
    ListNode *fast, *slow;
    fast = slow = head;
    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast) {
        slow = head;
        while (slow != fast) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    } 
    return nullptr;
  }
};


int main() {
  return 0;
}
