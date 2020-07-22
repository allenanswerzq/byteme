/* created   : 2020-07-22 07:19:15
 * accepted  : 2020-07-22 14:52:42
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void amax(int& a, int b) { a = max(a, b); }

const int N = 307;
vector<int> g[N];
int f[N][N];
int a[N];
int n;
int m;

void dfs(int u) {
  // NOTE: we must choose this node because it is a pre-class.
  f[u][1] = a[u];
  for (auto v : g[u]) {
    dfs(v);
    for (int t = m; t >= 1; t--) {
      for (int k = 1; k < t; k++) {
        trace(u, t, k, f[u][t - k]);
        // Choose k number of classes.
        amax(f[u][t], f[u][t - k] + f[v][k]);
      }
    }
  }
}

void solve() {
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int p, x; cin >> p >> x;
    g[p].push_back(i);
    a[i] = x;
  }
  m++;
  dfs(0);
  cout << f[0][m] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
