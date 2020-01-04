/* created   : 2020-01-04 19:55:15
 * accepted  : 2020-01-04 23:05:47
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

void amax(int& a, int b) { a = max(a, b); }

const int N = 300;
int f[N][N];
vector<int> g[N];
int score[N];
int n;
int m;

void dfs(int u) {
  for (auto v : g[u]) {
    dfs(v);
    // state
    for (int t = m; t >= 0; t--) {
      // action
      for (int k = 0; k <= m; k++) {
        if (t >= k) {
          amax(f[u][t], f[u][t - k] + f[v][k]);
        }
      }
    }
  }
  if (u != 0) {
    for (int t = m; t > 0; t--) {
      f[u][t] = f[u][t - 1] + score[u];
    }
  }
}

void solve() {
  cin >> n >> m;
  for (int v = 1; v <= n; v++) {
    int u, x; cin >> u >> x;
    g[u].push_back(v);
    score[v] = x;
  }
  dfs(0);
  cout << f[0][m] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
