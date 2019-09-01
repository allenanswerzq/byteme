/* created   : 2019-08-13 09:08:18
 * accepted  : 2019-08-13 09:16:40
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
  ll x1, y1, x2, y2, x3, y3;
  cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  pair<ll, ll> x = {x2 - x1, y2 - y1};
  pair<ll, ll> y = {x3 - x2, y3 - y2};
  ll dot = x.x * y.x + x.y * y.y;
  ll cross = x.x * y.y - x.y * y.x;
  trace(dot, cross);
  if (dot > 0) {
    cout << "TOWARDS" << "\n";
  }
  else if (cross > 0) {
    cout << "LEFT" << "\n";
  }
  else {
    cout << "RIGHT" << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
