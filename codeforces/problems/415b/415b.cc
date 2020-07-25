/* created   : 2020-03-02 21:06:59
 * accepted  : 2020-03-02 21:36:02
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
  ll n, a, b; cin >> n >> a >> b;
  for (int i = 0; i < n; i++) {
    ll w; cin >> w;
    ll t = w * a / b;
    ll extra = w * a - t * b;
    ll ans = extra / a;
    cout << ans << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
