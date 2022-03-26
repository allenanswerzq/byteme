/* created   : 2022-03-26 14:47:32
 * accepted  : 2022-03-26 17:15:04
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<ll, 2>;

void solve() {
  int N; cin >> N;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  if (N == 2) {
    cout << "2 2\n";
    cout << "1 1\n";
    return;
  }
  vector<vector<ar>> f(N, vector<ar>(2));
  vector<ar> vis(N);
  std::function<void(int, int, int)> dfs = [&](int u, int b, int parent) {
    if (vis[u][b]) return; // If pair (u, b) is already computed before
    vis[u][b] = 1;
    auto & ans = f[u][b];
    ans = {b, b ? -(ll)g[u].size() : -1};
    for (int v : g[u]) {
      if (v == parent) continue;
      dfs(v, b, u);
      dfs(v, b ^ 1, u);
      auto cur = f[v][b ^ 1];
      if (b == 0) {
        // u is a not good vertex
        cur = max(cur, f[v][b]);
      }
      ans[0] += cur[0]; // the maxinum good vertices
      ans[1] += cur[1]; // the minumum weights
    }
  };
  dfs(0, 0, -1);
  dfs(0, 1, -1);
  auto ans = max(f[0][0], f[0][1]);
  cout << ans[0] << " " << -ans[1] << "\n";
  vector<int> is_good(N);
  std::function<void(int, ar, int parent)> build = [&](int u, ar val, int parent) {
    if (val == f[u][0]) {
      is_good[u] = 0;
      for (int v : g[u]) {
        if (v == parent) continue;
        build(v, max(f[v][0], f[v][1]), u);
      }
    }
    else {
      is_good[u] = 1;
      for (int v : g[u]) {
        if (v == parent) continue;
        build(v, f[v][0], u);
      }
    }
  };
  build(0, ans, -1);
  trace(f);
  for (int i = 0; i < N; i++) {
    cout << (is_good[i] ? g[i].size() : 1) << (i == N - 1 ? '\n' : ' ');;
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
