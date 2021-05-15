/* created   : 2021-01-11 12:40:50
 * accepted  : 2021-01-12 12:58:39
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

vector<set<int>> g;
vector<int> vis;
vector<set<int>> ans;
int N, M;

void bfs(int s) {
  deque<int> qu;
  vector<int> dist(N);
  qu.push_back(s);
  dist[s] = 1;
  while (qu.size()) {
    int u = qu.front();
    vis[u] = 1;
    qu.pop_front();
    for (int v : g[u]) {
      if (dist[v]) {
        if (dist[v] < dist[u]) {
          // Do nothing
        }
        else if (dist[v] == dist[u]) {
          if (v < u) {
            // Do nothing
          }
          else {
            trace("same depth", u, v);
            // ans.insert({u, v});
            ans[u].insert(v);
          }
        }
        else {
          trace(u, v, dist[v], dist[u]);
          // ans.insert({u, v});
          ans[u].insert(v);
          // assert(false);
        }
      }
      else {
        trace("forwarding", u, v);
        dist[v] = dist[u] + 1;
        qu.push_back(v);
        ans[u].insert(v);
        // ans.insert({u, v});
      }
    }
  }
}

void solve_bfs() {
  cin >> N >> M;
  g.resize(N);
  vector<pair<int, int>> edge;
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].insert(v);
    g[v].insert(u);
    edge.push_back({u, v});
  }
  vis.resize(N);
  ans.resize(N);
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      bfs(i);
    }
  }
  trace(ans);
  Graphviz gv(GraphDrawType::Directed);
  for (auto& it : edge) {
    int u = it.first, v = it.second;
    if (ans[u].count(v)) {
      gv.gvAddEdge(u, v);
      cout << u + 1 << " " << v + 1 << "\n";
    }
    else if (ans[v].count(u)) {
      gv.gvAddEdge(v, u);
      cout << v + 1 << " " << u + 1 << "\n";
    }
    else {
      trace(u, v);
      assert(false);
    }
  }
  gv.gvDrawGraph();
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
