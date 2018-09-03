#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

// Accepted
RandomListNode *copyRandomList(RandomListNode *head) {
  if (!head) return NULL;
  // store random pointer for each node
  unordered_map<RandomListNode*, RandomListNode*> rdm;
  // store new node for each node, respectively
  unordered_map<RandomListNode*, RandomListNode*> mp;

  RandomListNode* p = head, *copy, *q;
  copy = new RandomListNode(-1);
  q = copy;

  while (p) {
  q->next = new RandomListNode(p->label); 
  q = q->next;
  rdm[p] = p->random;
  mp[p] = q;
  p = p->next;
  }

  for (auto it=rdm.begin(); it!=rdm.end(); ++it) 
  mp[it->first]->random = mp[it->second];

  return copy->next;
}

int main(int argc, char** argv) {
  return 0;
}
