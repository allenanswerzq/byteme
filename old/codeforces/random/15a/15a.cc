/* created   : 2019-08-19 09:37:24
 * accepted  : 2019-08-19 09:54:54
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

int dcmp(double a, double b) {
  const double eps = 1e-9;
  if (fabs(a - b) < eps) {
    return 0;
  }
  if (eps + b < a) {
    return 1;
  }
  return -1;
}

void solve() {
  int n, t;
  cin >> n >> t;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  sort(a.begin(), a.end());
  trace(a);
  int ans = 2;
  for (int i = 0; i < n - 1; i++) {
    double d = abs(a[i].x - a[i + 1].x);
    d -= (a[i].y / 2.0 + a[i + 1].y / 2.0);
    ans += (d > t ? 2 : dcmp(d, t) == 0 ? 1 : 0);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
