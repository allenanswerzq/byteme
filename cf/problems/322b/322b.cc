/* created   : 2020-04-11 08:38:05
 * accepted  : 2020-04-11 09:10:15
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  ll r, g, b; cin >> r >> g >> b;
  ll ans = r / 3 + g / 3 + b / 3;
  ll mi = min({r, g, b});
  for (int i = 0; i < 3; i++) {
    if (mi >= i) {
      ll x = (r - i) / 3;
      ll y = (g - i) / 3;
      ll z = (b - i) / 3;
      ans = max(ans, x + y + z + i);
      trace(ans, x + y + z + i);
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
