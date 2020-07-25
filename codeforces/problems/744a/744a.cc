/* created   : 2019-10-20 20:31:34
 * accepted  : 2019-10-20 23:50:17
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int N = 1e3 + 7;
vector<int> g[N];
int use[N];
int edge;
int node;
int n;

void dfs(int u) {
  if (use[u]) {
    return;
  }
  use[u] = 1;
  node++;
  for (auto v : g[u]) {
    if (!use[v]) {
      edge++;
      dfs(v);
    }
  }
}

void solve() {
  int m, k;
  cin >> n >> m >> k;
  vector<int> sp(k);
  for (int i = 0; i < k; i++) {
    cin >> sp[i];
    sp[i]--;
  }
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  int mx = 0;
  int sp_edge = 0;
  int sp_node = 0;
  vector<pair<int, int>> gp;
  for (auto u : sp) {
    edge = 0;
    node = 0;
    dfs(u);
    mx = max(mx, node);
    gp.emplace_back(node, edge);
    sp_edge += edge;
    sp_node += node;
  }
  int nm_edge = m - sp_edge;
  int nm_node = n - sp_node;
  auto get = [](int x, int y) {
    return x * (x - 1) / 2 - y;
  };
  ll ans = 0;
  for (auto it : gp) {
    ans += get(it.x, it.y);
  }
  ans += get(nm_node, nm_edge);
  ans += mx * nm_node;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
