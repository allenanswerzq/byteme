/* created   : 2020-03-30 18:53:10
 * accepted  : 2020-03-30 19:12:45
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int l, d, v, g, r;
  cin >> l >> d >> v >> g >> r;
  double t = d * 1.0 / v;
  // g r g r g r
  double s = 0;
  bool turn = 0;
  while (s <= t) {
    if (turn == 0) {
      s += g;
    }
    else {
      s += r;
    }
    turn ^= 1;
  }
  trace(turn, s, t);
  double ans = l * 1.0 / v;
  if (turn == 0) {
  // If the last time is red when car get to traffic.
    ans += s - t;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(8);
  solve();
  return 0;
}
