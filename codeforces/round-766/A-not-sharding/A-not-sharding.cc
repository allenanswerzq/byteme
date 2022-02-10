/* created   : 2022-01-20 08:16:50
 * accepted  : 2022-01-20 08:30:19
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, M, R, C; cin >> N >> M >> R >> C;
  vector<string> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  R--, C--;
  if (A[R][C] == 'B') {
    cout << 0 << "\n";
    return;
  }
  for (int j = 0; j < M; j++) {
    if (A[R][j] == 'B') {
      cout << 1 << "\n";
      return;
    }
  }
  for (int i = 0; i < N; i++) {
    if (A[i][C] == 'B') {
      cout << 1 << "\n";
      return;
    }
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      if (A[i][j] == 'B') {
        cout << 2 << "\n";
        return;
      }
    }
  }
  cout << -1 << "\n";
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
