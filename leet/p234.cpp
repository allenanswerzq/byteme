#include<bits/stdc++.h>
using namespace std;

ListNode* reverse(ListNode* head) {
  if (!head) return nullptr;
  ListNode*pre=nullptr, *nxt=nullptr;
  while (head) {
  nxt = head->next;
  head->next = pre;
  pre = head;
  head = nxt;
  }  
  return pre; 
}

bool isPalindrome(ListNode* head) {
  if (!head || !head->next) return true;
  ListNode* slow=head;
  ListNode* fast=head;
  ListNode* h = head;
  while (fast->next && fast->next->next) {
  slow = slow->next;
  fast = fast->next->next;
  }
  slow->next = reverse(slow->next);
  slow = slow->next;
  while (slow) {
  if (h->val != slow->val)
    return false;
  h = h->next;
  slow = slow->next;
  }
  return true;
}

int main(int argc, char** argv) {
  return 0;
}
