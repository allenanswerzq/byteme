/* created   : 2021-08-03 22:20:57
 * accepted  : 2021-08-03 22:22:56
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int H, M; cin >> H >> M;
  int minutes = H * 60 + M;
  int ans = 24 * 60 - minutes;
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
