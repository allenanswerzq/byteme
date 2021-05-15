/* created   : 2020-11-17 16:58:25
 * accepted  : 2020-11-18 10:15:54
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void dfs(int u, vector<int>& use, vector<vector<array<ll, 2>>>& g) {
  use[u] = true;
  for (auto t : g[u]) {
    if (!use[t[0]]) {
      dfs(t[0], use, g);
    }
  }
}

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<array<ll, 2>>> g(N);
  vector<vector<array<ll, 2>>> z(N);
  for (int i = 0; i < M; i++) {
    ll u, v, c; cin >> u >> v >> c;
    u--, v--;
    g[u].push_back({v, c});
    z[v].push_back({u, c});
  }
  vector<int> visit0(N), visit(N);
  // Compute all the nodes that reachable from `0`
  dfs(0, visit0, g);
  // Compute all the nodes that reachable from `N - 1`
  dfs(N - 1, visit, z);
  const ll INF = 1e18;
  vector<ll> dist(N, -INF);
  dist[0] = 0;
  for (int i = 0; i < N - 1; i++) {
    for (int u = 0; u < N; u++) {
      for (auto& t : g[u]) {
        ll v = t[0], c = t[1];
        dist[v] = max(dist[v], dist[u] + c);
      }
    }
  }
  trace(visit0, visit, dist);
  for (int u = 0; u < N; u++) {
    for (auto& t : g[u]) {
      ll v = t[0], c = t[1];
      if (dist[u] + c > dist[v]) {
        if (visit0[u] && visit[v]) {
          cout << -1 << "\n";
          return;
        }
      }
    }
  }
  cout << dist[N - 1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
