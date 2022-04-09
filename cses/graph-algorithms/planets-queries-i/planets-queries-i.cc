/* created   : 2020-11-20 10:18:18
 * accepted  : 2020-11-20 12:12:18
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, Q; cin >> N >> Q;
  vector<int> A(N);
  for (int& a : A) {
    cin >> a;
    a--;
  }
  const int step = 30;
  vector<vector<int>> f(N, vector<int>(step));
  for (int j = 0; j < step; j++) {
    for (int i = 0; i < N; i++) {
      if (j == 0) {
        f[i][j] = A[i];
      }
      else {
        int u = f[i][j - 1];
        f[i][j] = f[u][j - 1];
      }
    }
  }
  trace(f);
  for (int i = 0; i < Q; i++) {
    int x, k; cin >> x >> k;
    x--;
    for (int j = 0; j < step; j++) {
      if ((k >> j) & 1) {
        x = f[x][j];
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
