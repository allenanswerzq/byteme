#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
  cout << "[ ";
  for (auto x:v)
  cout << x << " ";
  cout <<"] " << endl;
}

ListNode* insertionSortList(ListNode* head) {
  if (!head) return NULL;
  
  ListNode *p = head;
  ListNode *sorted = new ListNode(INT_MIN);
  while (p) {
  ListNode *x = p->next;
  ListNode *y = sorted;
  // find the right place to insert
  while (y->next && y->next->val < p->val)
    y = y->next;
  p->next = y->next;
  y->next = p;
  p = x;
  }    
  return sorted;
}

ListNode* insertionSortList(ListNode* head) {
  if (!head) return NULL;

  ListNode *dummy = new ListNode(0);
  ListNode *cur = head;
  while (cur) {
  ListNode *next = cur->next;
  ListNode *pre = dummy;
  while (pre->next!=NULL && pre->next->val < cur->val)
     pre = pre->next; 
  cur->next = pre->next;
  pre->next = cur;
  cur = next;
  }
  return dummy->next;
}

int main(int argc, char** argv) {
  return 0;
}
