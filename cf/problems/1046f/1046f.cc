/* created   : 2020-03-29 10:53:49
 * accepted  : 2020-03-29 11:09:42
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
#define xuyixuyi()
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll x, f; cin >> x >> f;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    // a[i] - (y * x + y * f) <= 0
    if (a[i] > x) {
      ans += a[i] / (x + f) * f;
      if (a[i] % (x + f) > x) {
        ans += f;
      }
      trace(i, x + f, ans);
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
