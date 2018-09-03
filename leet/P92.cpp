#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
    cout << x << " ";
  cout <<"] " << endl;
}

// Perfect
// Accepted
ListNode* reverseBetween(ListNode* head, int m, int n) {
  if(!head) return NULL;
  // NOTE: dummy node is very good
  // use dummy node to unity operations on all nodes
  ListNode *dummy = new ListNode(0);
  dummy->next = head;
  int k = 0;
  ListNode* p = dummy;
  ListNode* x, *next, *prev=NULL;
  while(p) {
    if(k == m-1) x = p;
    else if(k == m) {
      ListNode *y = p;
      while (k<=n && p) {
        next = p->next;
        p->next = prev;
        prev = p;
        p = next;
        k++;
      }
      y->next = next;
      x->next = prev;
      return dummy->next;
    }
    p = p->next;
    k++;
  }
  return dummy->next;
}  

int main(int argc, char** argv) {
  return 0;
}
