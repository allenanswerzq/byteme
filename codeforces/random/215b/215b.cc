//=============================================================
// Name        : 215b
// Date        : Wed Jul  3 22:18:55 CST 2019
// Accepted    : Thu Jul  4 09:59:29 CST 2019
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
  int n;
  cin >> n;
  vector<int> x(n);
  for (int i = 0; i < n; ++i) {
    cin >> x[i];
  }
  int m;
  cin >> m;
  vector<int> y(m);
  for (int i = 0; i < m; ++i) {
    cin >> y[i];
  }
  int k;
  cin >> k;
  vector<int> z(k);
  for (int i = 0; i < k; ++i) {
    cin >> z[i];
  }
  int a, b;
  cin >> a >> b;
  sort(x.begin(), x.end());
  sort(y.begin(), y.end());
  sort(z.begin(), z.end());
  double d = a * 1.0 * z[0] / (b * y[m - 1]) + 1;
  double ans = x[n - 1] * 1.0 / sqrt(d);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  solve();
  return 0;
}
