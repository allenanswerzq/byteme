/* created   : 2021-03-27 19:56:44
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 4>;

void solve() {
  int N, M; cin >> N >> M;
  vector<vector<int>> A(N + 1, vector<int>(M + 1));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      cin >> A[i][j];
    }
  }
  vector<vector<ar>> cnt(N + 4, vector<ar>(M + 4));
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      // up
      cnt[i][j][0] = (A[i][j] ? cnt[i - 1][j][0] + 1 : 0);
      // down
      cnt[N - i + 1][j][1] = (A[N - i + 1][j] ? cnt[N - i + 2][j][1] + 1 : 0);
      // left
      cnt[i][j][2] = (A[i][j] ? cnt[i][j - 1][2] + 1 : 0);
      // right
      cnt[i][M - j + 1][3] = (A[i][M - j + 1] ? cnt[i][M - j + 2][3] + 1 : 0);
    }
  }
  // trace(cnt);
  ll ans = 0;
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= M; j++) {
      // 0, 1, 2, 3
      for (int k = 0; k < 4; k++) {
        for (int w = 0; w < 4; w++) {
          if (w == (k ^ 1) || w == k) continue;
          ans += max(min(cnt[i][j][k] / 2, cnt[i][j][w]) - 1, 0);
        }
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
