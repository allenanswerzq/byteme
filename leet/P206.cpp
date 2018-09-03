#include<bits/stdc++.h>
using namespace std;

// iteratively approach
ListNode* reverseList(ListNode* head) {
  if (!head) return nullptr;
  ListNode *prev = nullptr;
  ListNode *cur = head;
  while (cur)  {
  ListNode *next = cur->next;
  cur->next = prev;
  prev = cur;
  cur = next;
  }
  return prev;
}

// recursively
ListNode* reverseList(ListNode* head) {
  if (!head || !head->next) return head;
  ListNode *root = reverseList(head->next);
  // Note: hard to understand at first looking
  head->next->next = head;
  head->next = nullptr;
  return root;
}

int main(int argc, char** argv) {
  return 0;
}
