/* Name        : c
 * Creat       : Fri Jul 12 22:30:10 CST 2019
 * Accept      : Fri Jul 12 22:57:08 CST 2019
 * Author      : landcold7
 * Action speaks louder more than words
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  ll w, h, x, y;
  cin >> w >> h >> x >> y;
  int ok = 0;
  if (x * 2 == w && y * 2 == h) {
    ok = 1;
  }
  cout << h * w / 2.0 << " " << ok << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(15) << fixed;
  solve();
  return 0;
}
