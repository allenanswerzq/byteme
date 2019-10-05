//============================================================================
// Name        : 166a
// Date        : Thu Apr 11 21:21:38 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
#include "bits/stdc++.h"
using namespace std;

struct Node {
  int p, t;
  friend dbstream& operator<<(dbstream& os, Node& a) {
    os << a.p << " " << a.t << "\n";
    return os;
  }
};

void solve() {
  int n, k;
  cin >> n >> k;
  vector<Node> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].p >> a[i].t;
  }
  sort(all(a), [](Node& a, Node& b){
    if (a.p == b.p) {
      return a.t < b.t;
    } else {
      return a.p > b.p;
    }
  });
  trace(a);
  k -= 1;
  int ret = 1;
  for (int i = k + 1; i < n; ++i) {
    if (a[i].p == a[k].p && a[i].t == a[k].t) {
      ++ret;
    }
  }
  for (int i = k - 1; i >= 0; --i) {
    if (a[i].p == a[k].p && a[i].t == a[k].t) {
      ++ret;
    }
  }
  output(ret);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}

