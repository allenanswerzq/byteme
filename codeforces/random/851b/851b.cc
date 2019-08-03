/*
 * created   : 2019-07-31 19:14:02
 * accepted  : 2019-07-31 19:14:02
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
  ll d1 = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
  ll d2 = (x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2);
  if ((y3 - y2) * (x2 - x1) == (y2 - y1) * (x3 - x2) || (d1 != d2)) {
    cout << "No" << "\n";
    return;
  }
  cout << "Yes" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
