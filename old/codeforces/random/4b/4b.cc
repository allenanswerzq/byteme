/* created   : 2019-09-03 00:05:09
 * accepted  : 2019-09-03 00:05:10
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
  int n, m; cin >> n >> m;
  vector<pair<int, int>> a(n);
  int x = 0;
  int y = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
    x += a[i].x;
    y += a[i].y;
  }
  if (m < x || y < m) {
    cout << "NO\n";
    return;
  }
  cout << "YES\n";
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    ans[i] = a[i].x;
  }
  m -= accumulate(ans.begin(), ans.end(), 0);
  for (int i = 0; i < n; i++) {
    if (0 < m && ans[i] < a[i].y) {
      int d = a[i].y - ans[i];
      ans[i] += min(d, m);
      m -= d;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
