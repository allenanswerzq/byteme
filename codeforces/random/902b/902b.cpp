//=============================================================
// Name        : 902b
// Date        : Thu Jun 13 16:38:19 CST 2019
// Accepted    : Thu Jun 13 21:21:04 CST 2019
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

vector<vector<int>> a;
vector<int> now;

void dfs(int u, int col) {
  now[u] = col;
  for (auto v : a[u]) {
    dfs(v, col);
  }
}

void solve() {
  int n;
  cin >> n;
  a = vector<vector<int>>(n);
  for (int i = 0; i < n - 1; ++i) {
    int p;
    cin >> p;
    p--;
    a[p].push_back(i + 1);
  }
  vector<int> color(n);
  for (int i = 0; i < n; ++i) {
    cin >> color[i];
  }
  trace(a, color);
  now = vector<int>(n);
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    if (now[i] != color[i]) {
      trace(i, color[i]);
      dfs(i, color[i]);
      ans++;
      trace(i, now);
    }
  }
  assert(now == color);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
