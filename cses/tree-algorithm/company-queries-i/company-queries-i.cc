/* created   : 2020-12-12 10:09:18
 * accepted  : 2020-12-12 10:38:35
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, Q; cin >> N >> Q;
  const int K = 20;
  vector<vector<int>> f(N, vector<int>(K, -2));
  for (int i = 1; i < N; i++) {
    int x; cin >> x;
    x--;
    f[i][0] = x;
  }
  for (int k = 1; k < K; k++) {
    for (int i = 0; i < N; i++) {
      int p = f[i][k - 1];
      if (p >= 0) {
        f[i][k] = f[p][k - 1];
      }
    }
  }
  for (int i = 0; i < Q; i++) {
    int x, k; cin >> x >> k;
    x--;
    for (int j = 0; j < K; j++) {
      if (k >> j & 1) {
        x = f[x][j];
        if (x < 0) break;
      }
    }
    cout << x + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
