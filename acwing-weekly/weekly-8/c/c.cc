/* created   : 2021-08-06 07:16:54
 * accepted  : 2021-08-06 08:57:19
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<int>> g(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    // reverse edge
    g[v].push_back(u);
  }
  int K; cin >> K;
  vector<int> P(N);
  for (int i = 0; i < K; i++) {
    cin >> P[i];
    P[i]--;
  }
  const int INF = 1e9;
  vector<int> dist(N, INF);
  // The number of short paths can reach to a node
  vector<int> cnt(N);
  deque<int> qu;
  qu.push_back(P[K - 1]);
  dist[P[K - 1]] = 0;
  while (qu.size()) {
    int u = qu.front(); qu.pop_front();
    for (int v : g[u]) {
      if (dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        cnt[v] = 1;
        qu.push_back(v);
      }
      else if (dist[v] == dist[u] + 1) {
        cnt[v]++;
      }
    }
  }
  trace(dist, cnt);
  int mi = 0;
  int mx = 0;
  for (int i = 0; i + 1 < K; i++) {
    if (dist[P[i]] == dist[P[i + 1]] + 1) {
      // Next step is walking on the shortest path
      if (cnt[P[i]] > 1) {
        // This node has multiple shortest path, chose a different
        // path with the given one
        mx++;
      }
    }
    else {
      mi++, mx++;
    }
  }
  cout << mi << " " << mx << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
