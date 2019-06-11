//=============================================================
// Name        : 915b
// Date        : Tue Jun 11 19:33:49 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, p, l, r;
  cin >> n >> p >> l >> r;
  int ans = 0;
  if (p < l) {
    ans = l - p + 1;
    if (r < n) {
      ans += r - l + 1;
    }
  } else if (p > r) {
    ans = p - r + 1;
    if (l > 1) {
      ans += r - l + 1;
    }
  } else {
    if (l == 1 && r != n) {
      ans = r - p + 1;
    } else if (l != 1 && r == n) {
      ans = p - l + 1;
    } else if (l == 1 && r == n) {
      ans = 0;
    } else {
      ans = min(p - l, r - p) + 1;
      ans += r - l + 1;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
