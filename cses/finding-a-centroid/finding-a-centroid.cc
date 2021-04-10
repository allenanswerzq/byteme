/* created   : 2021-04-10 09:48:16
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

int dfs(vector<vector<int>>& g, int u, int p) {
  int n = g.size();
  bool ok = true;
  int tot = 1;
  for (int v : g[u]) {
    if (v == p) continue;
    int cur = dfs(g, v, u);
    tot += cur;
    ok &= (cur <= n / 2);
  }
  ok &= (n - tot <= n / 2);
  if (ok) {
    cout << u + 1 << "\n";
    exit(0);
  }
  return tot;
}

void solve() {
  int N; cin >> N;
  vector<vector<int>> g(N);
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(g, 0, -1);
  assert(false);
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
