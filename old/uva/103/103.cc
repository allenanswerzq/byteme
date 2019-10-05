/*
 * creat   : 2019-07-17 09:38:57
 * accept  : 2019-07-17 12:22:41
 * author  : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

int n, k, mx;
const int N = 37;
vector<vector<int>> g(N);
vector<int> ans;

void dfs(int u, int pr, vector<int>& path) {
  path.push_back(u);
  if (sz(g[u]) == 0) {
    if (sz(path) >= mx) {
      // trace(mx, path);
      mx = sz(path);
      ans = path;
    }
  }
  for (auto v : g[u]) {
    if (v != pr) {
      dfs(v, u, path);
    }
  }
  path.pop_back();
}

void solve() {
  vector<vector<int>> a(n, vector<int>(k));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < k; ++j) {
      cin >> a[i][j];
    }
  }
  auto check = [&](int x, int y) {
    vector<int> d = a[x];
    vector<int> e = a[y];
    sort(d.begin(), d.end());
    sort(e.begin(), e.end());
    int cnt = 0;
    for (int i = 0; i < k; ++i) {
      cnt += (d[i] < e[i]);
    }
    // trace(x, y, cnt, d, e);
    return cnt == k;
  };
  // O(n * n)
  for (int i = 0; i < N; ++i) {
    g[i].clear();
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      if (check(i, j)) {
        trace(i, j);
        g[i].push_back(j);
      }
      else if (check(j, i)) {
        g[j].push_back(i);
      }
    }
  }
  trace(g);
  mx = 0;
  ans.clear();
  for (int i = 0; i < n; ++i) {
    vector<int> path;
    dfs(i, -1, path);
  }
  cout << mx << "\n";
  for (int i = 0; i < mx; ++i) {
    cout << ans[i] + 1 << (i == mx - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n >> k) {
    solve();
  }
  return 0;
}
