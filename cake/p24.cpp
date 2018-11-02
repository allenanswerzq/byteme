#include<bits/stdc++.h>
using namespace std;

class Node {
public:
  int val;
  Node *next;
  Node(int x) : val(x), next(nullptr) {}
};

Node* reverseList(Node *head) {
  if (!head) return nullptr;
  Node *p = head;
  Node *prev = nullptr;
  while (p) {
    Node *nxt = p->next;
    p->next = prev;
    prev = p;
    p = nxt;
  }
  return prev;
}

int main() {
  return 0;
}
