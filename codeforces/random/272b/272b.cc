/* created   : 2019-08-11 15:22:32
 * accepted  : 2019-08-11 15:28:52
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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    a[i] = __builtin_popcount(x);
  }
  trace(a);
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    mp[a[i]]++;
  }
  ll ans = 0;
  for (auto it : mp) {
    ans += (ll) it.y * (it.y - 1) / 2;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
