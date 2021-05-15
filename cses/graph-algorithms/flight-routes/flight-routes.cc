/* created   : 2020-11-19 09:26:59
 * accepted  : 2020-11-19 10:49:56
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, M, K; cin >> N >> M >> K;
  vector<vector<array<int, 2>>> g(N);
  for (int i = 0; i < M; i++) {
    int a, b, c; cin >> a >> b >> c;
    a--, b--;
    g[a].push_back({b, c});
  }
  vector<vector<ll>> dist(N);
  priority_queue<array<ll, 2>, vector<array<ll, 2>>> qu;
  qu.push({0, 0});
  while (qu.size()) {
    auto top = qu.top();
    qu.pop();
    ll c = -top[0], u = top[1];
    dist[u].push_back(c);
    //     1
    //    |  \
    //    |   2
    //    |  /
    //     4
    if (dist[u].size() > K) continue;
    for (auto& t : g[u]) {
      int v = t[0], w = t[1];
      qu.push({-(c + w), v});
    }
  }
  assert(dist[N - 1].size() >= K);
  for (int i = 0; i < K; i++) {
    cout << dist[N - 1][i] << (i == K - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
