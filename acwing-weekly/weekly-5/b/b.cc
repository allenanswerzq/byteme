/* created   : 2021-07-30 08:29:49
 * accepted  : 2021-07-30 22:49:17
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // x * k ^ i = y
  int N, K; cin >> N >> K;
  const ll INF = 1e17 + 7;
  for (int i = 0; i < N; i++) {
    ll y; cin >> y;
    assert(y < INF);
    if (y == 0) continue;
    ll p = 1;
    for (int j = 0; j <= i; j++) {
      assert(p < INF);
      if (p > y / K) {
        cout << "NO\n";
        return;
      }
      p *= K;
      assert(p < INF);
    }
    assert(p > 0);
    if (y % p != 0) {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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
