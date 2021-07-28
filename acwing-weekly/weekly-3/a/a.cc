/* created   : 2021-07-27 22:31:17
 * accepted  : 2021-07-27 22:51:11
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  ll N, M, R, C;
  cin >> N >> M >> R >> C;
  // ans = max(|x - R| + |y - C|)
  vector<ar> nodes = {
    {1, 1},
    {1, M},
    {N, 1},
    {N, M}
  };
  ll ans = 0;
  for (auto& p : nodes) {
    ans = max(ans, abs(p[0] - R) + abs(p[1] - C));
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
