#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

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
  if (!head || 
      !head->next) return head;
  ListNode *root = reverseList(head->next);
  // Note: hard to understand first look 
  head->next->next = head;
  head->next = nullptr;
  return root;
}

int main(int argc, char** argv) {
    return 0;
}
