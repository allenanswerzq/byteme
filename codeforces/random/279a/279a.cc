/*
 * created   : 2019-08-01 23:03:24
 * accepted  : 2019-08-01 23:18:09
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
  int x, y;
  cin >> x >> y;
  int a = 0;
  int b = 0;
  int turn = 0;
  int t = 1;
  int ans = 0;
  while (!(a == x && b == y)) {
    trace(a, b);
    if (turn == 0) {
      a++;
      if (a == x && b == y) {
        break;
      }
      if (a == t) {
        turn = 1;
        ans++;
      }
    }
    else if (turn == 1) {
      b++;
      if (a == x && b == y) {
        break;
      }
      if (b == t) {
        turn = 2;
        ans++;
      }
    }
    else if (turn == 2) {
      a--;
      if (a == x && b == y) {
        break;
      }
      if (a == -t) {
        turn = 3;
        ans++;
      }
    }
    else if (turn == 3) {
      b--;
      if (a == x && b == y) {
        break;
      }
      if (b == -t) {
        turn = 0;
        t++;
        ans++;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
