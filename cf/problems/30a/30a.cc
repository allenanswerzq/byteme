/* created   : 2020-03-26 00:24:21
 * accepted  : 2020-03-26 00:49:53
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#define xuyixuyi()
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int a, b, n; cin >> a >> b >> n;
  if (b == 0) {
    cout << 0 << '\n';
    return;
  }
  if (a == 0) {
    if (b) {
      cout << "No solution" << '\n';
    }
    else {
      cout << 0 << '\n';
    }
    return;
  }
  if (b % a) {
    cout << "No solution" << '\n';
    return;
  }
  int y = b / a;
  // x ^ n = y
  if (y < 0 && n % 2 == 0) {
    cout << "No solution" << '\n';
    return;
  }
  if (n == 1) {
    cout << y << '\n';
    return;
  }
  trace(n, y, a, b);
  for (int x = -40; x <= 40; x++) {
    ll t = 1;
    for (int j = 0; j < n; j++) {
      t *= x;
    }
    if (t == y) {
      cout << x << '\n';
      return;
    }
  }
  cout << "No solution" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
