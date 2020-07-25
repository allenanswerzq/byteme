/* created   : 2020-05-01 10:57:14
 * accepted  : 2020-05-01 11:25:40
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  vector<pair<int, int>> a(m);
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    x--;
    a[i] = {x, y};
  }
  int mx = a[0].y + a[0].x;
  for (int i = 0; i + 1 < m; i++) {
    int d = a[i + 1].x - a[i].x;
    int f = abs(a[i + 1].y - a[i].y);
    if (d < f) {
      cout << "IMPOSSIBLE\n";
      return;
    }
    else if (d == f) {
      mx = max({mx, a[i + 1].y, a[i].y});
    }
    else {
      d = d - f - 1;
      int x = max(a[i + 1].y , a[i].y);
      mx = max(mx, x + (d + 1) / 2);
    }
  }
  mx = max(mx, a.back().y + n - 1 - a.back().x);
  cout << mx << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
