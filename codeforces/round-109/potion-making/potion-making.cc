/* created   : 2021-09-06 07:16:45
 * accepted  : 2021-09-06 07:29:05
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int K; cin >> K;
  int ans = 1e9;
  // e / (e + 3) = K / 100
  // 100 * e == (e + 3) * K
  for (int i = 1; i < 100; i++) {
    for (int j = 0; j < 100; j++) {
      if (100 * i == K * (i + j)) {
        trace(i, j);
        ans = min(ans, i + j);
      }
    }
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
