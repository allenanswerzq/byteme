/*
 * created   : 2019-07-29 09:30:17
 * accepted  : 2019-07-29 09:37:15
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
  int n;
  cin >> n;
  string s;
  cin >> s;
  int mx = 0;
  for (int len = n / 2; len >= 0; len--) {
    if (s.substr(0, len) == s.substr(len, len)) {
      mx = len;
      break;
    }
  }
  trace(mx);
  int ans = mx + (n - 2 * mx) + (mx > 0);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
