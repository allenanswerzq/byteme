/* created   : 2021-10-17 10:09:47
 * accepted  : 2021-10-17 10:34:59
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // a ^ x = k * m + y
  // a ^ x % m = y
  ll a, m, y; cin >> a >> m >> y;
  for (ll k = 0; ; k++) {
    ll t = k * m + y;
    ll lo = -1, hi = 100000000;
    while (lo + 1 < hi) {
      ll md = lo + (hi - lo) / 2;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int c; cin >> c;
  for (int i = 0; i < c; i++) {
    solve();
  }
  return 0;
}
