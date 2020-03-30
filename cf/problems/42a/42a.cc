/* created   : 2020-03-29 15:48:31
 * accepted  : 2020-03-29 16:00:13
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#define xuyixuyi()
#endif
typedef long long ll;

void solve() {
  int n, v; cin >> n >> v;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  auto check = [&](double md) {
    double sum = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] * md > b[i]) return false;
      sum += a[i] * md;
    }
    return sum < v;
  };
  trace(a, b);
  double lo = 0;
  double hi = 100;
  int cnt = 0;
  while (abs(hi - lo) > 1e-9) {
    cnt++;
    double md = (lo + hi) / 2;
    if ((check(md))) {
      lo = md;
    }
    else {
      hi = md;
    }
  }
  trace(cnt);
  double ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] * lo;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(20);
  solve();
  return 0;
}
