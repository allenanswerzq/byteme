/* created   : 2020-05-21 23:38:06
 * accepted  : 2020-05-22 00:35:09
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

pair<ll, ll> rec(ll n, ll p) {
  if (n == 0) {
    return {0, 0};
  }
  ll len = 1ll << (n - 1);
  ll tot = 1ll << (2 * n - 2);
  auto ans = rec(n - 1, p % tot);
  ll x = ans.x, y = ans.y;
  ll r = p / tot;
  if (r == 0) {
    // clockwise rotate 90: (y, -x)
    // vertical reflect: (-y, -x)
    // shift to left up corner: (-y + len, -x + len)
    return {-y - len, -x + len};
  }
  else if (r == 1) {
    // shift to right up corner: (x + len, y + len)
    return {x + len, y + len};
  }
  else if (r == 2) {
    // shift to right bottom corner.
    return {x + len, y - len};
  }
  else {
    // counter clockwise rotate 90: (-y, x)
    // vertical reflect: (y, x)
    // shift to left bottom corner.
    return {y - len, x - len};
  }
}

void solve() {
  ll n, a, b; cin >> n >> a >> b;
  a--, b--;
  auto pa = rec(n, a);
  auto pb = rec(n, b);
  double x = pa.x - pb.x;
  double y = pa.y - pb.y;
  double ans = sqrt(x * x + y * y) * 5;
  cout << (ll) round(ans) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
