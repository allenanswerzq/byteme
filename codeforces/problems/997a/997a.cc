/* created   : 2019-10-06 16:18:10
 * accepted  : 2019-10-06 17:05:15
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
  int n, x, y; cin >> n >> x >> y;
  string s; cin >> s;
  int g = 0;
  for (int i = 0; i < n; ) {
    char ch = s[i];
    while (i < n && s[i] == ch) {
      i++;
    }
    if (ch == '0') {
      g++;
    }
  }
  trace(g);
  if (g == 0) {
    cout << 0 << '\n';
    return;
  }
  assert(g > 0);
  ll ans = (ll) (g - 1) * min(x, y) + y;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
