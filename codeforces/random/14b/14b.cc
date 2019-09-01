/* created   : 2019-08-14 09:57:49
 * accepted  : 2019-08-14 10:07:50
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
  int n, x;
  cin >> n >> x;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
    if (a[i].x > a[i].y) {
      swap(a[i].x, a[i].y);
    }
  }
  trace(a);
  const int INF = (1 << 30);
  int ans = INF;
  for (int i = 0; i < 1200; i++) {
    bool ok = 1;
    for (auto t : a) {
      if (!(t.x <= i && i <= t.y)) {
        ok = 0;
      }
    }
    if (ok) {
      ans = min(ans, abs(i - x));
    }
  }
  cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
