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
};

bool containCycle(Node* firstNode) {
  Node *s, *f;
  s = f = firstNode;

  while (f && f->next) {
    s = f->next;
    f = f->next->next;
    // Case: if slow pointer and fast pointer meet
    if (s == f) {
      return true;
    }
  }
  // Case: fast hit the end of the list
  return false;
}

int main() {
   
  return 0;
}
