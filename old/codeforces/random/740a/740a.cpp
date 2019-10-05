//=============================================================
// Name        : 740a
// Date        : Fri Jun  7 16:39:04 CST 2019
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
  ll n, a, b, c;
  cin >> n >> a >> b >> c;
  int k = -1;
  for (int i = 0; i < 4; ++i) {
    if ((n + i) % 4 == 0) {
      k = i;
    }
  }
  trace(k);
  ll ans = -1;
  if (k == 0) {
    ans = 0;
  } else if (k == 1) {
    ans = min(a, b + c);
    ans = min(ans, 2 * b + a);
    ans = min(ans, 3 * c);
  } else if (k == 2) {
    ans = min(2 * a, b);
    ans = min(ans, 2 * c);
  } else if (k == 3) {
    ans = min(3 * a, c);
    ans = min(ans, b + a);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
