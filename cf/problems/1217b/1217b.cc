/* created   : 2020-04-06 15:26:04
 * accepted  : 2020-04-06 16:34:12
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  ll n, x; cin >> n >> x;
  trace(n, x);
  ll md = -1e18;
  ll mx = -1e18;
  for (int i = 0; i < n; i++) {
    ll d, h; cin >> d >> h;
    mx = max(mx, d);
    md = max(md, d - h);
  }
  if (mx >= x) {
    cout << 1 << '\n';
  }
  else {
    if (md <= 0) {
      cout << -1 << '\n';
    }
    else {
      x -= mx;
      cout << 1 + (x + md - 1) / md << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    solve();
  }
  return 0;
}
