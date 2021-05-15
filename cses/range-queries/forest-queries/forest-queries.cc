/* created   : 2020-11-28 17:42:27
 * accepted  : 2020-11-28 18:03:59
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N, Q; cin >> N >> Q;
  vector<string> A(N);
  for (string& a : A) {
    cin >> a;
  }
  vector<vector<int>> f(N + 1, vector<int>(N + 1));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      f[i][j] = f[i - 1][j] + f[i][j - 1] - f[i - 1][j - 1];
      f[i][j] += (A[i - 1][j - 1] == '*');
    }
  }
  trace(f);
  for (int i = 0; i < Q; i++) {
    int y1, x1, y2, x2; cin >> y1 >> x1 >> y2 >> x2;
    int ans = f[y2][x2] - f[y1 - 1][x2] - f[y2][x1 - 1] + f[y1 - 1][x1 - 1];
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
