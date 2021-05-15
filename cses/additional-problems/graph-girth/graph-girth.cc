/* created   : 2021-01-31 20:08:43
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int INF = 1e9 + 7;
vector<vector<int>> g;
int ans;
int N;
int M;

// compute the shortest cycle go through node s
void bfs(int s) {
  deque<int> qu;
  qu.push_back(s);
  vector<int> dist(N, INF);
  dist[s] = 0;
  while (qu.size()) {
    int u = qu.front();
    qu.pop_front();
    for (int v : g[u]) {
      if (dist[v] != INF) {
        if (dist[u] <= dist[v]) {
          ans = min(ans, dist[u] + dist[v] + 1);
        }
      }
      else {
        dist[v] = dist[u] + 1;
        qu.push_back(v);
      }
    }
  }
}

void solve() {
  cin >> N >> M;
  g.resize(N);
  Graphviz gv;
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
    gv.gvAddEdge(u, v);
  }
  gv.gvDrawGraph();
  ans = INF;
  for (int i = 0; i < N; i++) {
    bfs(i);
  }
  cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
