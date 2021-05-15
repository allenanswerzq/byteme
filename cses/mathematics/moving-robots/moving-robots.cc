/* created   : 2020-12-26 09:26:10
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  // The probility of every cell being empty after n steps.
  vector<vector<double>> p(8, vector<double>(8, 1));
  auto step = [&](int x, int y) {
    vector<vector<array<double, 8>>> f(N + 1, vector<array<double, 8>>(8));
    f[0][x][y] = 1;
    for (int k = 0; k < N; k++) {
      for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
          int cnt = (i > 0) + (i < 7) + (j > 0) + (j < 7);
          if (i > 0) f[k + 1][i - 1][j] += f[k][i][j] / cnt;
          if (i < 7) f[k + 1][i + 1][j] += f[k][i][j] / cnt;
          if (j > 0) f[k + 1][i][j - 1] += f[k][i][j] / cnt;
          if (j < 7) f[k + 1][i][j + 1] += f[k][i][j] / cnt;
        }
      }
    }
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 8; j++) {
        p[i][j] *= (1 - f[N][i][j]);
      }
    }
  };
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
  // Starts from here, compute the probility of reaching to all other cells.
      step(i, j);
    }
  }
  // Compute the final answer by applying linearlity.
  double ans = 0;
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      ans += p[i][j];
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout << fixed << setprecision(6);
  solve();
  return 0;
}
