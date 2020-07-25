/* created   : 2019-11-20 08:11:39
 * accepted  : 2019-11-20 18:17:30
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

const int N = 3e5 + 7;
vector<int> g[N];
int ignore_x;
int parent_y;
int n;
int x;
int y;

int dfs(int u, int pr, bool* reach) {
  trace("dfs", pr, u);
  if (u == y) {
    parent_y = pr;
    *reach = true;
  }
  int tot_nodes = 1;
  for (int v : g[u]) {
    if (u == x && v == ignore_x) {
      continue;
    }
    if (v != pr) {
      tot_nodes += dfs(v, u, reach);
    }
  }
  return tot_nodes;
}

void solve() {
  cin >> n >> x >> y;
  x--, y--;
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  ignore_x = -1;
  parent_y = -1;
  bool reach = false;
  for (int v : g[x]) {
    dfs(v, x, &reach);
    if (reach) {
      ignore_x = v;
      break;
    }
  }
  assert(ignore_x != -1 && parent_y != -1);
  int a = dfs(x, -1, &reach);
  int b = dfs(y, parent_y, &reach);
  ll ans = (ll) n * (n - 1) - (ll) a * b;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
