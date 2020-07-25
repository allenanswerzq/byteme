/* created   : 2020-03-29 22:04:02
 * accepted  : 2020-03-29 22:45:57
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
  ll sum = 0;
  int mx = 0, my = 0;
  int ix = 1e9, iy = 1e9;
  for (int i = 0; i < n; i++) {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    sum += abs(y1 - y2) * abs(x1 - x2);
    mx = max({mx, x1, x2});
    my = max({my, y1, y2});
    ix = min({ix, x1, x2});
    iy = min({iy, y1, y2});
  }
  trace(mx, my, ix, iy);
  if (abs(ix - mx) != abs(iy - my)) {
    cout << "NO" << '\n';
    return;
  }
  if (sum != abs(ix - mx) * 1ll * abs(ix - mx)) {
    cout << "NO" << '\n';
    return;
  }
  cout << "YES" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
