/* created   : 2020-10-31 21:19:00
 * accepted  : 2020-10-31 21:46:25
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  ll x, y; cin >> x >> y;
  ll m = max(x, y);
  ll n = min(x, y);
  ll s = (m - 1) * (m - 1) + 1;
  ll t = m * m;
  ll a = 0;
  if (x > y) {
    a = (m & 1) ? s + n - 1 : t - n + 1;
  }
  else {
    a = (m & 1) ? t - n + 1 : s + n - 1;
  }
  cout << a << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int n; cin >> n;
  while (n--) solve();
  return 0;
}
