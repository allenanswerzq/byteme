/* created   : 2021-01-12 19:27:03
 * accepted  : 2021-01-12 20:07:47
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

// NOTE: Same problem, different solution

vector<vector<pair<int, int>>> g;
vector<pair<int, int>> edges;
vector<int> vis;
vector<int> seen;
vector<pair<int, int>> ans;
int N, M;

void dfs(int u) {
  vis[u] = 1;
  for (auto& e : g[u]) {
    int id = e.first;
    int v = e.second;
    if (seen[id]) {
      assert(vis[v]);
      continue;
    }
    else if (vis[v]) {
      ans.push_back({v, u});
      seen[id] = -1;
    }
    else {
      seen[id] = 1;
      ans.push_back({u, v});
      dfs(v);
    }
  }
}

void solve() {
  cin >> N >> M;
  g.resize(N);
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    edges.push_back({u, v});
    int c = edges.size() - 1;
    g[u].push_back({c, v});
    g[v].push_back({c, u});
  }
  vis.resize(N);
  seen.resize(edges.size());
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      dfs(i);
    }
  }
  Graphviz gv(GraphDrawType::Directed);
  for (int i = 0; i < M; i++) {
    // assert(seen[i] != 0);
    // int u = edges[i].first;
    // int v = edges[i].second;
    // if (seen[i] == -1) {
    //   swap(u, v);
    // }
    int u = ans[i].first;
    int v = ans[i].second;
    gv.gvAddEdge(u, v);
    cout << u + 1 << " " << v + 1 << "\n";
  }
  gv.gvDrawGraph();
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
