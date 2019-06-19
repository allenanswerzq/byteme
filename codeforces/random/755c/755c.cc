//=============================================================
// Name        : 755c
// Date        : Tue Jun 18 16:30:01 CST 2019
// Accepted    : Tue Jun 18 16:36:48 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

struct union_find {
  vector<int> e;
  int component;
  union_find(int n) : e(n, -1), component(n) {}

  int size(int x) {
    return -e[find(x)];
  }

  int find(int x) {
    return e[x] < 0 ? x : e[x] = find(e[x]);
  }

  void join(int u, int v) {
    int a = find(u);
    int b = find(v);
    if (a == b) {
      return;
    }
    if (e[a] > e[b]) {
      swap(a, b);
    }
    e[a] += e[b];
    e[b] = a;
    component--;
  }
};

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  union_find uf(n);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    x--;
    uf.join(x, i);
  }
  cout << uf.component << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
