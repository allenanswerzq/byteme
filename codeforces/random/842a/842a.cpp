//=============================================================
// Name        : 842a
// Date        : Sat Jun  8 15:45:20 CST 2019
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
  ll l, r, x, y, k;
  cin >> l >> r >> x >> y >> k;
  int a = l, b = x;
  bool ok = 0;
  while (a <= r && b <= y) {
    if (a == b * 1ll * k) {
      ok = 1;
      break;
    } else if (a > b * 1ll * k) {
      b++;
    } else {
      a++;
    }
  }
  cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
