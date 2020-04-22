/* created   : 2020-04-22 22:29:45
 * accepted  : 2020-04-22 23:21:55
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  int ps = 0;
  const int inf = 1e9;
  int mx = -inf, mi = inf;
  for (int i = 0; i < n; i++) {
    if (a[i].y == 1) {
      mx = max(mx, 1900 - ps);
    }
    else {
      mi = min(mi, 1899 - ps);
    }
    ps += a[i].x;
  }
  trace(mi, mx);
  // mx <= x <= mi
  if (mx > mi) {
    cout << "Impossible" << '\n';
  }
  else if (mi == inf) {
    cout << "Infinity" << '\n';
  }
  else {
    cout << mi + ps << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
