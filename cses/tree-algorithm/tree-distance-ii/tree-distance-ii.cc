/* created   : 2020-12-10 22:15:32
 * accepted  : 2020-12-10 23:01:46
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> d(N);
  vector<int> s(N);
  vector<int> vis(N);
  std::function<void(int)> dfs = [&](int u) {
    vis[u] = 1;
    s[u] = 1;
    for (int v : g[u]) {
      if (!vis[v]) {
        d[v] = d[u] + 1;
        dfs(v);
        s[u] += s[v];
      }
    }
  };
  dfs(0);
  vector<ll> ans(N);
  std::function<void(int, ll)> dfs2 = [&](int u, ll p) {
    vis[u] = 1;
    ans[u] = p;
    for (int v : g[u]) {
      if (!vis[v]) {
        dfs2(v, p - s[v] + (N - s[v]));
      }
    }
  };
  ll sum = accumulate(all(d), 0ll);
  vis.assign(N, 0);
  dfs2(0, sum);
  for (int i = 0; i < N; i++) {
    cout << ans[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
