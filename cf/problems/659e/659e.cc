/* created   : 2019-11-12 07:36:56
 * accepted  : 2019-11-12 07:45:40
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

const int N = 1e5 + 7;
vector<int> g[N];
bool use[N];
bool cycle;
int n;
int m;

void dfs(int u, int pr = -1) {
  if (use[u]) {
    cycle = true;
    return;
  }
  use[u] = true;
  for (int v : g[u]) {
    if (v != pr) {
      dfs(v, u);
    }
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (!use[i]) {
      cycle = false;
      dfs(i);
      if (!cycle) {
        ans++;
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
