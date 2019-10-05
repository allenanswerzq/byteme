/*
 * created   : 2019-07-29 20:06:29
 * accepted  : 2019-07-29 22:07:10
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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  int x = b * c - a * d;
  int y = b * c;
  trace(x, y);
  int z = a * d - c * b;
  int w = d * a;
  trace(z, w);
  if (x > 0) {
    int g = __gcd(x, y);
    cout << x / g << "/" << y / g << "\n";
  }
  else {
    int g = __gcd(z, w);
    cout << z / g << "/" << w / g << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
