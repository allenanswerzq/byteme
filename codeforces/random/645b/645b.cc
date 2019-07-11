//=============================================================
// Name        : 645b
// Date        : Thu Jul  4 14:40:47 CST 2019
// Accepted    : Thu Jul  4 14:56:51 CST 2019
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
  ll n, k;
  cin >> n >> k;
  k = min(k, n / 2);
  ll ans = k * (n - 1 + n - k) / 2;
  ans += (n - 2 * k) * k;
  ans += k * (k - 1) / 2;
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
