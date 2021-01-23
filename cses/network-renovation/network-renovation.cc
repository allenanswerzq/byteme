/* created   : 2021-01-21 22:12:35
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

vector<vector<int>> g;
vector<int> vis;
vector<int> pre;
int N;
int node;
int depth;

void dfs(int u, int d = 1) {
  vis[u] = 1;
  if (depth < d) {
    depth = d;
    node = u;
  }
  for (int v : g[u]) {
    if (!vis[v]) {
      pre[v] = u;
      dfs(v, d + 1);
    }
  }
}

int depthest_node(int u) {
  vis.assign(N, 0);
  pre.assign(N, -1);
  node = -1;
  depth = 0;
  dfs(u);
  return node;
}

void solve() {
  cin >> N;
  g.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int start = depthest_node(0);
  int end = depthest_node(start);
  vector<int> diameter(N);
  while (node != start) {
    diameter[node] = 1;
    node = pre[node];
  }
  diameter[start] = 1;
  vector<int> other;
  other.push_back(end);
  for (int i = 0; i < N; i++) {
    if (!diameter[i]) {
      other.push_back(i);
    }
  }
  other.push_back(start);
  trace(other);
  cout << other.size() - 1 << "\n";
  for (int i = 0; i + 1 < other.size(); i++) {
    cout << other[i] + 1 << " " << other[i + 1] + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
