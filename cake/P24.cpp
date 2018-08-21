#include<bits/stdc++.h>
using namespace std;


const double EPS = 1e-9;
int cmp(double x, double y = 0, double tol = EPS) {
  return (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1;
}

class Node {
public:
  int val;
  Node *next;
  Node(int x)
    : val(x), next(nullptr) {}
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
  Node *head = new Node(1);
  Node *p = head;
  for (int i=2; i<=5; ++i) {
    p->next = new Node(i);
    p = p->next;
  }
  p = reverseList(head);
  while (p) {
    cout << p->val << " ";
    p = p->next;
  }
  cout << '\n';
  return 0;
}
