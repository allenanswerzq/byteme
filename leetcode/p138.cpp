#include <bits/stdc++.h>
using namespace std;

// TODO
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (!head) return nullptr;

    // Store random pointer for each node
    unordered_map<RandomListNode*, RandomListNode*> rdm;

    // Store new node for each node, respectively
    unordered_map<RandomListNode*, RandomListNode*> mp;

    RandomListNode *cur = head, *dummy, *p;
    dummy = new RandomListNode(-1);
    p = dummy;

    while (cur) {
      p->next = new RandomListNode(cur->label); 
      p = p->next;
      rdm[cur] = cur->random;
      mp[cur] = p;
      cur = cur->next;
    }

    for (auto it : rdm)
      mp[it->first]->random = mp[it->second];

    return dummy->next;
  }
};

int main() {
  return 0;
}
