/*
 * created   : 2019-08-04 23:49:50
 * accepted  : 2019-08-04 23:54:31
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
  int a, b;
  cin >> a >> b;
  // a - k = b - k
  // a - b = 0

  // -a + k = b - k
  // 2 * k = b + a

  // a - k = -b + k
  // a + b = 2 * k

  // -a + k = -b + k
  // a = b
  int ans = -1;
  if (a == b) {
    ans = 0;
  }
  else if ((a + b) % 2 == 0) {
    ans = (a + b) / 2;
  }
  if (ans == -1) {
    cout << "IMPOSSIBLE" << "\n";
    return;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
