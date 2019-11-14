/* created   : 2019-11-14 08:20:06
 * accepted  : 2019-11-14 08:40:47
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

const int N = 2e5 + 7;
vector<int> g[N];
int order[N];
int ids[N];
int sub[N];
int cnt;
int n;
int m;

void dfs(int u, int pr = -1) {
  order[cnt] = u;
  ids[u] = cnt++;
  sub[u] = 1;
  for (int v : g[u]) {
    if (v != pr) {
      dfs(v, u);
      sub[u] += sub[v];
    }
  }
}

void solve() {
  cin >> n >> m;
  for (int u = 1; u < n; u++) {
    int v; cin >> v;
    v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 0; i < n; i++) {
    sort(g[i].begin(), g[i].end());
  }
  dfs(0);
  trace(mt(order, n));
  trace(mt(sub, n));
  for (int i = 0; i < m; i++) {
    int u, k; cin >> u >> k;
    u--;
    int ix = ids[u];
    if (sub[u] < k) {
      cout << -1 << '\n';
    }
    else {
      cout << order[ix + k - 1] + 1 << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
