/* created   : 2020-11-17 16:11:58
 * accepted  : 2020-11-17 16:28:20
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<array<int, 2>>> g(N);
  for (int i = 0; i < M; i++) {
    int u, v, c; cin >> u >> v >> c;
    u--, v--;
    g[u].push_back({v, c});
  }
  const ll INF = 1e18;
  vector<ll> dist(N, INF);
  dist[0] = 0;
  priority_queue<array<ll, 2>, vector<array<ll, 2>>> qu;
  qu.push({0, 0});
  while (qu.size()) {
    auto top = qu.top(); qu.pop();
    ll u = top[1], d = -top[0];
    if (d > dist[u]) continue;
    for (auto& t : g[u]) {
      int v = t[0], c = t[1];
      if (d + c < dist[v]) {
        dist[v] = d + c;
        qu.push({-dist[v], v});
      }
    }
  }
  for (int i = 0; i < N; i++) {
    assert(dist[i] != INF);
    cout << dist[i] << (i == N - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
