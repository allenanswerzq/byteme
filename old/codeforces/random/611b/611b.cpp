//=============================================================
// Name        : 611b
// Date        : Tue Jun 11 20:27:33 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

ll get(ll a) {
  ll x = 1, cnt = 0;
  while (x <= a) {
    cnt++;
    x <<= 1;
  }
  ll ans = 0, t = cnt - 1;
  while (t > 1) {
    ans += t-- - 1;
  }
  trace(a, cnt, ans);
  for (int i = 1; i < cnt; ++i) {
    // 0111111 (not valid)
    // 1011111
    // 1101111
    ll s = 0;
    for (int j = 0; j < cnt; ++j) {
      s = s * 2 + (j == i ? 0 : 1);
    }
    if (s > a) {
      break;
    } else {
      ans++;
    }
  }
  return ans;
}

void solve() {
  ll a, b;
  cin >> a >> b;
  cout << get(b) - get(a - 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
