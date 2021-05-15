/* created   : 2020-11-24 16:13:14
 * accepted  : 2020-11-24 17:20:41
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

const int mod = 1e9 + 7;

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<int>> g(N, vector<int>(N));
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u][v]++;
  }
  // trace(g);
  vector<vector<int>> f(1<<N, vector<int>(N));
  f[1][0] = 1;
  for (int i = 2; i < 1<<N; i++) {
    if (i>>(N-1) & 1 && i != (1<<N) - 1) {
      continue;
    }
    for (int j = 0; j < N; j++) {
      if (i>>j & 1) {
        int t = i ^ 1<<j;
        for (int k = 0; k < N; k++) {
          if (t>>k & 1 && g[k][j]) {
            f[i][j] += (ll) g[k][j] * f[t][k] % mod;
            f[i][j] %= mod;
          }
        }
      }
    }
  }
  cout << f[(1<<N) - 1][N - 1] << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
