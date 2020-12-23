/* created   : 2020-12-23 22:12:51
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, A, B; cin >> N >> A >> B;
  int M = 6 * N + 1;
  vector<vector<double>> f(N + 1, vector<double>(M));
  f[0][0] = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      for (int k = 1; k <= 6; k++) {
        if (j + k < M) {
          f[i + 1][j + k] += f[i][j] * 1.0 / 6;
        }
      }
    }
  }
  double ans = 0;
  for (int i = A; i <= B; i++) {
    ans += f[N][i];
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  cout << setprecision(6) << fixed;
  solve();
  return 0;
}
