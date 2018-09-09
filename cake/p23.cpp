#include<bits/stdc++.h>
using namespace std;

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
