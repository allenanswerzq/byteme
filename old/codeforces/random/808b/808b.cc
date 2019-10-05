//=============================================================
// Name        : 808b
// Date        : Sat Jun 29 12:25:48 CST 2019
// Accepted    : Sat Jun 29 12:30:27 CST 2019
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  ll sum = 0, win = 0;
  for (int i = 0; i < n; ++i) {
    if (i < k) {
      win += a[i];
    } else {
      sum += win;
      win -= a[i - k];
      win += a[i];
    }
  }
  sum += win;
  trace(sum);
  double ans = sum * 1.0 / (n - k + 1);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  solve();
  return 0;
}
