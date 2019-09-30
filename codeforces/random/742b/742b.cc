/* created   : 2019-09-13 00:23:14
 * accepted  : 2019-09-13 00:34:46
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
  int n, x; cin >> n >> x;
  unordered_map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int v; cin >> v;
    mp[v]++;
  }
  ll ans = 0;
  for (auto it : mp) {
    int y = x ^ it.x;
    if (mp.count(y)) {
      if (y != it.x) {
        ans += (ll) it.y * mp[y];
      }
      else {
        ans += (ll) mp[y] * (mp[y] - 1);
      }
    }
  }
  cout << ans / 2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
