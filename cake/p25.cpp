#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node(int x) : val(x), next(nullptr) {}
};

int kthToLastNode(int kth, Node *head) {
  // Case: head is nullptr
  if (!head) return -1;
  // Case: input is not correct
  if (kth <= 0) return -1;

  Node *p1 = head;
  Node *p2 = head;

  while (p2 && kth-- > 0) {
    p2 = p2->next;
  }
  // Case: kth is greater than the length of this list
  if (!p2 && kth>0) {
    printf("Not gonna happen\n");
    return -1;
  }
  // Case: normal situation
  // Cache analysis: temporal locality
  while (p1 && p2) {
    p1 = p1->next;
    p2 = p2->next;
  }
  return p1->val;
}

int main() {
  return 0;
}
