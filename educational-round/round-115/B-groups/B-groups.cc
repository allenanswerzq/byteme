/* created   : 2022-01-09 15:24:22
 * accepted  : 2022-01-09 15:33:39
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 5>;

void solve() {
  int N; cin >> N;
  vector<ar> A(N);
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 5; j++) {
      cin >> A[i][j];
    }
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      if (i == j) continue;
      int t = 0;
      int x = 0;
      int y = 0;
      for (int k = 0; k < N; k++) {
        t += (A[k][i] | A[k][j]);
        x += A[k][i];
        y += A[k][j];
      }
      if (t == N && x >= N / 2 && y >= N / 2) {
        cout << "YES\n";
        return;
      }
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
