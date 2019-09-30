/* created   : 2019-09-21 23:03:09
 * accepted  : 2019-09-21 23:15:41
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

void solve() {
  // x <= w / (3 * n);
  // x <= a(0..n - 1)
  // x <= a(n, 2 * n - 1) / 2
  int n, w; cin >> n >> w;
  vector<int> v(2 * n);
  for (int i = 0; i < 2 * n; i++) {
    cin >> v[i];
  }
  sort(v.begin(), v.end());
  double x = v[n] / 2.0;
  x = min(v[0] * 1.0, x);
  x = min(x, w / (3.0 * n));
  double ans = 3.0 * n * x;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(20);
  solve();
  return 0;
}
