/* created   : 2021-01-21 22:12:35
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

vector<vector<int>> g;
vector<int> vis;
vector<int> leaf;
int N;

void dfs(int u) {
  vis[u] = true;
  for (int v : g[u]) {
    if (vis[v]) continue;
    dfs(v);
  }
  if (g[u].size() == 1) {
    leaf.push_back(u);
  }
}

void solve() {
  cin >> N;
  g.resize(N);
  vis.resize(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0);
  trace(leaf);
  int n = leaf.size();
  cout << (n + 1) / 2 << "\n";
  for (int i = 0; i < (n + 1) / 2; i++) {
    int u = leaf[i];
    int v = leaf[n / 2 + i];
    cout << u + 1 << " " << v + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
