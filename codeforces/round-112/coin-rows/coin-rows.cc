/* created   : 2021-08-13 22:34:31
 * accepted  : 2021-08-14 09:30:25
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int M; cin >> M;
  vector<vector<int>> A(2, vector<int>(M));
  vector<vector<ll>> pre(2, vector<ll>(M + 1));
  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < M; j++) {
      cin >> A[i][j];
      pre[i][j + 1] = pre[i][j] + A[i][j];
    }
  }
  trace(A);
  ll ans = 1e18;
  for (int i = 0; i < M; i++) {
    // -----ixxxxx
    //      -----M
    ll a = pre[0][i + 1] + pre[1][M] - pre[1][i];
    ll b1 = pre[0][M] - pre[0][i + 1];
    ll b2 = pre[1][i];
    trace(i, a, max(b1, b2));
    ans = min(ans, max(b1, b2));
  }
  cout << ans << "\n";
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
