/* created   : 2020-11-15 09:54:29
 * accepted  : 2020-11-15 10:35:39
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<int>> g(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vector<int> use(N);
  vector<int> pre(N);
  trace(g);
  int cycle_end = -1;
  int cycle_start = -1;
  std::function<bool(int, int)> dfs = [&](int u, int p) {
    assert(use[u] == 0);
    use[u] = 1;
    trace(u, p);
    for (int v : g[u]) {
      trace(u, v, p, g[u]);
      if (v != p) {
        if (use[v]) {
          cycle_end = u;
          cycle_start = v;
          return true;
        }
        pre[v] = u;
        if (dfs(v, u)) return true;
      }
    }
    return false;
  };
  for (int i = 0; i < N; i++) {
    if (!use[i]) {
      pre[i] = -1;
      if (dfs(i, -1)) {
        break;
      }
    }
  }
  if (cycle_end == -1) {
    cout << "IMPOSSIBLE\n";
  }
  else {
    // trace(cycle, pre);
    vector<int> ans;
    int u = cycle_end;
    while (u != cycle_start) {
      ans.push_back(u);
      u = pre[u];
    }
    ans.push_back(cycle_start);
    reverse(all(ans));
    ans.push_back(cycle_start);
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
      if (i > 0) {
        cout << " ";
      }
      cout << ans[i] + 1;
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
