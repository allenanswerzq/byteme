/* created   : 2019-09-08 17:15:22
 * accepted  : 2019-09-08 17:28:38
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

const int N = 1e5 + 7;
vector<int> g[N];
double ans = 0;

void dfs(int u, double prob, int path, int pr=-1) {
  int n = 0;
  for (auto v : g[u]) {
    if (v != pr) {
      n++;
    }
  }
  if (n == 0) {
  // This is a leaf node.
    trace(u, prob, path);
    ans += prob * path;
    return;
  }
  for (auto v : g[u]) {
    if (v != pr) {
      dfs(v, prob * 1.0 / n, path + 1, u);
    }
  }
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(0, 1.0, 0, -1);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(20);
  solve();
  return 0;
}
