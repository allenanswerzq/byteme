//=============================================================
// Name        : 1027b
// Date        : Sun Jun  9 11:21:43 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, q;
  cin >> n >> q;
  ll a = (n * 1ll * n + 1) / 2;
  ll ans = -1;
  for (int i = 0; i < q; ++i) {
    ll x, y;
    cin >> x >> y;
    ans = (x - 1) / 2 * n + (y + 1) / 2;
    if (x % 2 == 0) {
      if ((x + y) % 2 == 0) {
        ans += (n + 1) / 2;
      } else {
        ans += n / 2;
      }
    }
    if ((x + y) % 2 == 1) {
      ans += a;
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
