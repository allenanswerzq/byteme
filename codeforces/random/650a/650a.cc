/* created   : 2019-09-06 09:54:37
 * accepted  : 2019-09-06 18:49:04
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
  int n; cin >> n;
  map<int, int> mx, my;
  map<pair<int, int>, int> mp;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    mx[x]++;
    my[y]++;
    mp[{x, y}]++;
  }
  trace(mx, my, mp);
  ll ans = 0;
  for (auto it : mx) {
    ans += (ll) it.y * (it.y - 1) / 2;
  }
  for (auto it : my) {
    ans += (ll) it.y * (it.y - 1) / 2;
  }
  for (auto it : mp) {
    ans -= (ll) it.y * (it.y - 1) / 2;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
