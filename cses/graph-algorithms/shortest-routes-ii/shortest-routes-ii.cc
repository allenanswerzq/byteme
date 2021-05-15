/* created   : 2020-11-17 16:29:11
 * accepted  : 2020-11-17 16:55:39
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M, Q; cin >> N >> M >> Q;
  const ll INF = 1e18;
  vector<vector<ll>> dist(N, vector<ll>(N, INF));
  for (int i = 0; i < N; i++) {
    dist[i][i] = 0;
  }
  for (int i = 0; i < M; i++) {
    int u, v; ll c; cin >> u >> v >> c;
    u--, v--;
    dist[u][v] = min(dist[u][v], c);
    dist[v][u] = min(dist[v][u], c);
  }
  for (int k = 0; k < N; k++) {
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (dist[i][k] + dist[k][j] < dist[i][j]) {
          dist[i][j] = dist[i][k] + dist[k][j] ;
        }
      }
    }
  }
  trace(dist);
  for (int i = 0; i < Q; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    if (dist[u][v] == INF) {
      cout << -1 << "\n";
    }
    else {
      cout << dist[u][v] << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
