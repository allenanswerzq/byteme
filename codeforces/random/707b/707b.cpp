//=============================================================
// Name        : 707b
// Date        : Wed Jun  5 14:23:44 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, m, k;
  cin >> n >> m >> k;
  vector<vector<pair<int, int>>> a(n);
  for (int i = 0; i < m; ++i) {
    int u, v, l;
    cin >> u >> v >> l;
    u--, v--;
    a[u].emplace_back(v, l);
    a[v].emplace_back(u, l);
  }
  vector<bool> was(n);
  for (int i = 0; i < k; ++i) {
    int x;
    cin >> x;
    was[--x] = 1;
  }
  const int inf = 1e9 + 7;
  int ret = inf;
  for (int i = 0; i < n; ++i) {
    if (was[i] == 1) {
      for (auto v : a[i]) {
        if (!was[v.x]) {
          ret = min(ret, v.y);
        }
      }
    }
  }
  cout << (ret == inf ? -1 : ret) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
