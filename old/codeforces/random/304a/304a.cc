//=============================================================
// Name        : 304a
// Date        : Tue Jun 25 09:35:07 CST 2019
// Accepted    : Tue Jun 25 09:49:28 CST 2019
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

bool perfect_quare(long double x) {
  long double sr = sqrt(x);
  return fabs(sr - floor(sr)) <= 1e-9;
}

void solve() {
  int n;
  cin >> n;
  ll ans = 0;
  for (int a = 1; a <= n; ++a) {
    for (int c = a + 1; c <= n; ++c) {
      int x = c * c - a * a;
      if (x > 0 && perfect_quare(x)) {
        ans++;
      }
    }
  }
  cout << ans / 2 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
