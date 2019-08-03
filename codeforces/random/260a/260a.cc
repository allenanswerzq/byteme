/*
 * created   : 2019-07-22 21:35:58
 * accepted  : 2019-07-22 22:17:54
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  ll a, b, n;
  cin >> a >> b >> n;
  bool ok = 0;
  for (int i = 0; i <= 9; ++i) {
    ll x = a * 10 + i;
    if (x % b == 0) {
      a = x;
      ok = 1;
      break;
    }
  }
  if (!ok) {
    cout << -1 << "\n";
    return;
  }
  string ans = to_string(a);
  for (int i = 0; i < n - 1; ++i) {
    ans += string(1, '0');
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
