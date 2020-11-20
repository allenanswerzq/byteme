/* created   : 2020-11-19 20:07:55
 * accepted  : 2020-11-20 09:58:34
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int mod = 1e9 + 7;

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<array<int, 2>>> g(N);
  vector<vector<array<int, 2>>> z(N);
  for (int i = 0; i < M; i++) {
    int u, v, c; cin >> u >> v >> c;
    u--, v--;
    g[u].push_back({v, c});
    z[v].push_back({u, c});
  }
  const ll INF = 1e18;
  vector<vector<int>> pre(N);
  vector<ll> dist(N, INF);
  priority_queue<array<ll, 2>, vector<array<ll, 2>>> qu;
  dist[0] = 0;
  qu.push({0, 0});
  while (qu.size()) {
    auto top = qu.top();
    qu.pop();
    ll c = -top[0], u = top[1];
    if (c > dist[u]) continue;
    assert(c == dist[u]);
    for (auto& t : g[u]) {
      int v = t[0], w = t[1];
      if (c + w < dist[v]) {
        dist[v] = c + w;
        qu.push({-dist[v], v});
      }
    }
  }
  trace(dist);
  const int INFI = 1e9;
  vector<int> cnt(N);
  vector<int> mi(N, INFI);
  vector<int> mx(N);
  vector<int> vis(N);
  cnt[0] = 1;
  mi[0] = 0;
  std::function<void(int, ll)> dfs = [&](int u, ll c) {
    vis[u] = 1;
    for (auto t : z[u]) {
      int v = t[0], w = t[1];
      if (dist[v] + w == c) {
      // NOTE: ensure node v is a node on the shortest path
        if (vis[v] == 0) {
          dfs(v, dist[v]);
        }
        cnt[u] = (cnt[u] + cnt[v]) % mod;
        mi[u] = min(mi[u], mi[v] + 1);
        mx[u] = max(mx[u], mx[v] + 1);
      }
    }
    vis[u] = 2;
  };
  dfs(N - 1, dist[N - 1]);
  cout << dist[N - 1] << " " << cnt[N - 1] << " " << mi[N - 1] << " " << mx[N - 1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
