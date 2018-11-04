#include<bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

int length(ListNode *head) {
  if (!head) return 0;
  ListNode *p = head;
  int res = 0;
  while (p) {
  p = p->next;
  ++res;
  }
  return res;
}

class Solution {
public:
  ListNode* middleNode(ListNode* head) {
  ListNode *p, *q;
  int len = 0;
  if (!head) return null;
  if (!head->next) return head;
  len = length(head);
  p = head;
  if (len & 1) q = head->next;    
  else q = head->next->next;
  while (q) {
    p = p->next;
    q = q->next->next;
  }
  if (len % 2 == 0) return p->next;
  return p;
  }
};



int main() {
 

  int t; cin >> t;
  fori (i, 1, t + 1) {
  
  }  
  return 0;
}
