/* created   : 2019-09-20 23:38:22
 * accepted  : 2019-09-21 00:21:30
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  ll l, r, k; cin >> l >> r >> k;
  vector<ll> v;
  ll x = 1;
  for (int i = 0; ; i++) {
    if (l <= x && x <= r) {
      v.push_back(x);
    }
    if (x > r / k) {
      break;
    }
    x *= k;
  }
  if (v.empty()) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 0; i < (int) v.size(); i++) {
    if (i > 0) {
      cout << ' ';
    }
    cout << v[i];
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
