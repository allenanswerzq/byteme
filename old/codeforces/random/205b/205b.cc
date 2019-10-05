/* created   : 2019-08-10 17:24:46
 * accepted  : 2019-08-10 20:52:18
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
    cin >> a[i];
  }
  ll ans = 0;
  ll pr = a[0];
  for (int i = 1; i < n; i++) {
    ll x = a[i] + ans;
    if (x <= pr) {
      ans += pr - x;
    }
    else {
      pr = x;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
