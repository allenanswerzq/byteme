#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

int len(ListNode *head) {
  if (!head) return 0;
  return 1 + len(head->next); 
}

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  int la = len(headA);
  int lb = len(headB);
  if (la==0 || lb==0) return NULL;
  ListNode *p=headA, *q=headB;
  if (la > lb) {
  int x = la-lb;
  while (x) {
    p = p->next;
    --x;
  }
  } else {
  int x = lb - la;
  while (x) {
    q = q->next;
    --x;
  }
  } 
  while (p && q) {
  if (p == q) return p;
  p = p->next;
  q = q->next;
  }
  return NULL;
}

// more shorter code
ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
  int la = len(headA);
  int lb = len(headB);
  if (la==0 || lb==0) return NULL;
  ListNode *p = la > lb ? headA:headB;
  ListNode *q = la > lb ? headB:headA; 
  int x = abs(la-lb);
  while (x) {
  p = p->next;
  --x;
  }
  while (p && q) {
  if (p == q) return p;
  p = p->next;
  q = q->next;
  }
  return NULL;
}

int main(int argc, char** argv) {
  return 0;
}
