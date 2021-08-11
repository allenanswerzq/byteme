/* created   : 2021-08-10 08:10:23
 * accepted  : 2021-08-11 08:12:12
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

vector<int> bfs(int s, const vector<vector<int>>& g) {
  const int INF = 1e9;
  int n = g.size();
  vector<int> dist(n, INF);
  deque<int> qu;
  qu.push_back(s);
  dist[s] = 0;
  while (qu.size()) {
    int u = qu.front(); qu.pop_front();
    for (int v : g[u]) {
      if (dist[u] + 1 < dist[v]) {
        dist[v] = dist[u] + 1;
        qu.push_back(v);
      }
    }
  }
  return dist;
}

void solve() {
  int N, M, K; cin >> N >> M >> K;
  vector<int> sp(K);
  for (int i = 0; i < K; i++) {
    cin >> sp[i];
    sp[i]--;
  }
  trace(sp);
  vector<vector<int>> g(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  auto dist0 = bfs(0, g);
  auto dist1 = bfs(N - 1, g);
  // 1--> a -> b --> N
  // 1--> b -> a --> N
  // max{xi + yj, xj + yi} + 1
  sort(all(sp), [&](int i, int j) {
    return dist0[i] - dist0[j] < dist1[i] - dist1[j];
  });
  int ans = 0;
  int mx = dist0[sp[0]];
  for (int i = 1; i < K; i++) {
    // 1 --> mx --> i --> N
    ans = max(ans, mx + dist1[sp[i]] + 1);
    mx = max(mx, dist0[sp[i]]);
  }
  trace(dist0, dist1, sp, ans);
  ans = min(ans, dist0[N - 1]);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
