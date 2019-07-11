//=============================================================
// Name        : 400b
// Date        : Sat Jun 29 12:39:24 CST 2019
// Accepted    : Sat Jun 29 12:49:48 CST 2019
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

void solve() {
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  set<int> d;
  for (int i = 0; i < n; ++i) {
    int g = -1, s = -1;
    for (int j = 0; j < m; ++j) {
      if (a[i][j] == 'G') {
        g = j;
      }
      else if (a[i][j] == 'S') {
        s = j;
      }
    }
    assert(g != -1 && s != -1);
    if (s < g) {
      cout << -1 << "\n";
      return;
    }
    d.insert(s - g);
  }
  cout << sz(d) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
