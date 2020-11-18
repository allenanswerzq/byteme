/* created   : 2020-11-18 10:42:56
 * accepted  : 2020-11-18 11:10:31
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void compute(vector<vector<array<ll, 2>>>& g, vector<ll>& dist, int s) {
  priority_queue<array<ll, 2>, vector<array<ll, 2>>> qu;
  dist[s] = 0;
  qu.push({0, s});
  while (qu.size()) {
    auto top = qu.top();
    qu.pop();
    ll u = top[1], c = -top[0];
    if (c > dist[u]) continue;
    for (auto& t : g[u]) {
      ll v = t[0], w = t[1];
      if (dist[u] + w < dist[v]) {
        dist[v] = dist[u] + w;
        qu.push({-dist[v], v});
      }
    }
  }
}

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<array<ll, 2>>> g(N);
  vector<vector<array<ll, 2>>> z(N);
  for (int i = 0; i < M; i++) {
    int u, v, c; cin >> u >> v >> c;
    u--, v--;
    g[u].push_back({v, c});
    z[v].push_back({u, c});
  }
  const ll INF = 1e18 + 7;
  vector<ll> dist0(N, INF), dist(N, INF);
  compute(g, dist0, 0);
  compute(z, dist, N - 1);
  trace(dist0, dist);
  ll ans = INF;
  for (int u = 0; u < N; u++) {
    for (auto& e : g[u]) {
      ll v = e[0], c = e[1];
      // u ---> v(c)
      ans = min(ans, dist0[u] + c / 2 + dist[v]);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
