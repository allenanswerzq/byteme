#include<bits/stdc++.h>

using namespace std;

void printVector(vector<int>& v) {
    printf("[ ");
    for (auto x:v)
        printf("%d ", x); 
    printf("]\n");
}

// Accepted
ListNode* removeElements(ListNode* head, int val) {
  ListNode *dummy = new ListNode(0);  
  ListNode *p = dummy;
  ListNode *q = head;
  while (q) {
    if (q->val != val) {
      p->next = q;
      p = p->next;
      q = q->next;
      p->next = nullptr;
    } else q=q->next;
  }
  return dummy->next;
}

int main(int argc, char** argv) {
    return 0;
}
