/* created   : 2022-03-06 23:40:41
 * accepted  : 2022-03-07 00:14:42
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

ll ceil(ll a, ll b) { return (a + b - 1) / b; }

void solve() {
  ll Hc, Dc; cin >> Hc >> Dc;
  ll Hm, Dm; cin >> Hm >> Dm;
  ll K, W, A; cin >> K >> W >> A;
  // int tm = ceil(Hm / (Dc + x * W))
  // int tc = ceil((Hc + A * y) / Dm)
  // x + y = K
  ll lo = -1;
  ll hi = K + 1;
  while (lo + 1 <= hi) {
    ll md = (lo + hi) / 2;
    ll tm = ceil(Hm, Dc + md * W);
    ll tc = ceil(Hc + (K - md) * A, Dm);
    // characte attacks first, so equal also works
    if (tc >= tm) {
      trace(md, tm, tc);
      cout << "YES\n";
      return;
    }
    else {
      lo = md;
      if (lo == K) break;
    }
  }
  lo = -1;
  hi = K + 1;
  while (lo + 1 <= hi) {
    ll md = (lo + hi) / 2;
    ll tm = ceil(Hm, Dc + (K - md) * W);
    ll tc = ceil(Hc + md * A, Dm);
    if (tc >= tm) {
      trace(md, tm, tc);
      cout << "YES\n";
      return;
    }
    else {
      lo = md;
      if (lo == K) break;
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
