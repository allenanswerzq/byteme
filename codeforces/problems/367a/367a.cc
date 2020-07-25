/* created   : 2020-03-04 21:59:48
 * accepted  : 2020-03-04 22:50:30
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
#endif
typedef long long ll;

void solve() {
  string s; cin >> s;
  int n = s.size();
  vector<int> x(n + 1);
  vector<int> y(n + 1);
  for (int i = 0; i < n; i++) {
    x[i + 1] = x[i] + (s[i] == 'x');
    y[i + 1] = y[i] + (s[i] == 'y');
  }
  int m; cin >> m;
  for (int i = 0; i < m; i++) {
    int l, r; cin >> l >> r;
    l--, r--;
    if (r - l + 1 < 3) {
      cout << "YES" << '\n';
      continue;
    }
    int cx = x[r + 1] - x[l];
    int cy = y[r + 1] - y[l];
    int cz = (r - l + 1) - cx - cy;
    int mx = max(cx, max(cy, cz));
    int mi = min(cx, min(cy, cz));
    if (cx > 0 && cy > 0 && cz > 0 && mx - mi <= 1) {
      cout << "YES" << '\n';
    }
    else {
      cout << "NO" << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
