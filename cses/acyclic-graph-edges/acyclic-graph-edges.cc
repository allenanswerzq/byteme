/* created   : 2021-01-10 22:19:37
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

vector<vector<int>> g;
vector<pair<int, int>> ans;
vector<int> vis;

void dfs(int u, int p = -1) {
  trace(u);
  vis[u] = 1;
  for (int v : g[u]) {
    if (!vis[v]) {
      ans.push_back({u, v});
      dfs(v, u);
    }
    else if (v != p) {
      trace(u, v, vis[v]);
      // ans.push_back({v, u});
    }
  }
}

void solve() {
  int N, M; cin >> N >> M;
  g.resize(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  vis.resize(N);
  dfs(0);
  trace(ans);
  assert(ans.size() == M);
  for (int i = 0; i < M; i++) {
    cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
