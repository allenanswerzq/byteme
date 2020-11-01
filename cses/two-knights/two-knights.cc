/* created   : 2020-11-01 08:53:44
 * accepted  : 2020-11-01 09:31:09
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  // ...
  // ...
  // ...
  int n; cin >> n;
  vector<int> dx = {-1, 1, -2, 2};
  vector<int> dy = {-1, 1, -2, 2};
  for (int k = 1; k <= n; k++) {
    // x +- 1, y +- 2
    // x +- 2, y +- 1
    ll ans = k * k * 1ll * (k * k - 1) / 2;
    ll cur = 0;
    for (int i = 0; i < 4; i++) {
      for (int j = 0; j < 4; j++) {
        if (abs(dx[i]) == abs(dy[j])) continue;
        cur += max(0, (k - abs(dx[i]))) * max(0, (k - abs(dy[j]))) / 2;
      }
    }
    trace(ans, k, cur);
    cout << ans - cur << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
