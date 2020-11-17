/* created   : 2020-11-17 16:58:25
 * accepted  : 2020-11-17 20:17:43
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M; cin >> N >> M;
  vector<array<ll, 3>> e;
  for (int i = 0; i < M; i++) {
    ll u, v, c; cin >> u >> v >> c;
    u--, v--;
    e.push_back({u, v, c});
  }
  assert(e.size() == M);
  const ll INF = 1e18;
  vector<ll> dist(N, -INF);
  dist[0] = 0;
  for (int i = 0; i < N - 1; i++) {
    for (auto& t : e) {
      ll u = t[0], v = t[1], c = t[2];
      dist[v] = max(dist[v], dist[u] + c);
    }
  }
  for (int i = 0; i < N - 1; i++) {
    for (auto& t : e) {
      ll u = t[0], v = t[1], c = t[2];
      if (dist[u] + c > dist[v]) {
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
