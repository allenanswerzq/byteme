//=============================================================
// Name        : 893c
// Date        : Sun Jun  9 09:26:06 CST 2019
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

vector<int> gold;
vector<int> was;
vector<vector<int>> a;

int dfs(int u) {
  was[u] = 1;
  int ans = 1e9 + 7;
  for (auto v : a[u]) {
    if (!was[v]) {
      ans = min(ans, dfs(v));
    }
  }
  return min(ans, gold[u]);
};

void solve() {
  int n, m;
  cin >> n >> m;
  gold = vector<int>(n);
  for (int i = 0; i < n; ++i) {
    cin >> gold[i];
  }
  a = vector<vector<int>>(n);
  for (int i = 0; i < m; ++i) {
    int u, v;
    cin >> u >> v;
    u--, v--;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  was = vector<int>(n);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    trace(i, was);
    if (!was[i]) {
      ans += dfs(i);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
