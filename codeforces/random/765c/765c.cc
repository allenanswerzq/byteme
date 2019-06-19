//=============================================================
// Name        : 765c
// Date        : Mon Jun 17 21:57:17 CST 2019
// Accepted    : Mon Jun 17 22:26:47 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  ll k, a, b;
  cin >> k >> a >> b;
  if (a < b) {
    swap(a, b);
  }
  trace(k, a, b, a % k);
  ll ans = a / k + b / k;
  if (a % k != 0 && b / k == 0) {
    ans = -1;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
