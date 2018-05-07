#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <numeric>
#include <sstream>
#include <fstream>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <bitset>
#include <string>
#include <cstdio>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <stack>
#include <list>
#include <map>
#include <set>
using namespace std;

#define OUT
#ifdef OUT
#define PR(x) printf x 
#else   
#define PR(x) do { if (0) printf x; } while (0) 
#endif

#define PRT printf
#define FOR(i, a, b) for (int i=(a); i<(b); ++i)
#define FORD(i, a, b) for (int i=(a); i>(b); --i)
#define FORA(e, c) for (auto &e : c)
#define ALL(x) (x).begin(), (x).end()
#define MST(X, v) memset((X), (v), sizeof((X)))
#define LEN(X) strlen(X)
#define VI vector<int>
#define SZ(x) ((int)(x).size())
#define PII pair<int, int>
#define LL long long
#define F first
#define S second
#define MP make_pair
#define PB push_back
#define D(x) cerr << #x " is " << (x) << endl
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
  Node *head = new Node(1);
  Node *p = head;
  for (int i=2; i<=5; ++i) {
    p->next = new Node(i);
    p = p->next;
  }
  cout << kthToLastNode(6, head) << '\n';
  return 0;
}