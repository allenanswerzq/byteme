/* created   : 2019-09-08 19:45:45
 * accepted  : 2019-09-08 22:48:13
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int N = 1.5e5 + 7;
vector<int> g[N];
int use[N];

void dfs(int u, int& vecs, int& edges) {
  use[u] = 1;
  vecs++;
  // Each egde has been counted twice.
  edges += g[u].size();
  for (auto v : g[u]) {
    if (!use[v]) {
      dfs(v, vecs, edges);
    }
  }
}

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    if (!use[i]) {
      int edges = 0;
      int vecs = 0;
      dfs(i, vecs, edges);
      if (edges != (ll) vecs * (vecs - 1)) {
        cout << "NO\n";
        return;
      }
    }
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
