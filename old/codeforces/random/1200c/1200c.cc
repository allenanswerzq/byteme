/* created   : 2019-09-15 11:15:10
 * accepted  : 2019-09-15 12:01:05
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
  ll n, m, k; cin >> n >> m >> k;
  ll g = __gcd(n, m);
  n /= g;
  m /= g;
  for (int i = 0; i < k; i++) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    b--, d--;
    ll px = -1;
    ll py = -1;
    px = (a == 1 ? b / n : b / m);
    py = (c == 1 ? d / n : d / m);
    cout << (px == py ? "YES" : "NO") << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
