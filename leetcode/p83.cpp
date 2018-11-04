#include<bits/stdc++.h>
using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

// Accepted
ListNode* deleteDuplicates(ListNode* head) {
  if (!head) return NULL;
  ListNode *h = head;
  ListNode *p = head;
  ListNode *q = p->next;
  p->next = NULL;
  while(q) {
    if(q->val != p->val) {
      ListNode *t = q->next;
      p->next = q;
      p = p->next;
      p->next = NULL;
      q = t;
    } else {
      q = q->next;
    }
  }
  return h;
}

int main() {
  return 0;
}
