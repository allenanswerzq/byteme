/* created   : 2020-02-29 22:33:56
 * accepted  : 2020-02-29 23:03:53
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  ll t, s, q; cin >> t >> s >> q;
  int cnt = 1;
  while (1) {
    ll x = s * q;
    if (x >= t) {
      break;
    }
    cnt++;
    s = x;
  }
  cout << cnt << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
