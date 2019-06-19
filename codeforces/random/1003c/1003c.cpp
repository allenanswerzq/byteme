//=============================================================
// Name        : 1003c
// Date        : Sat Jun 15 15:05:14 CST 2019
// Accepted    : Sat Jun 15 15:19:44 CST 2019
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  vector<int> pr(n + 1);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pr[i + 1] = pr[i] + a[i];
  }
  double ans = 0;
  for (int i = k; i <= n; ++i) {
    for (int j = 0; j + i <= n; ++j) {
      double tmp = pr[j + i] - pr[j];
      ans = fmax(ans, tmp / i);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(15) << fixed;
  solve();
  return 0;
}
