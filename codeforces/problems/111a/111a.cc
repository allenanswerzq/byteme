/* created   : 2020-03-11 22:23:24
 * accepted  : 2020-03-11 23:04:22
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
#endif
typedef long long ll;
typedef pair<int, int> pii;

#define sqr(x) ((x) * (x))

void solve() {
  ll n, x, y; cin >> n >> x >> y;
  ll a = y - (n - 1);
  if (a <= 0) {
    cout << -1 << '\n';
    return;
  }
  if (n - 1 + a * a >= x) {
    for (int i = 0; i < n - 1; i++) {
      cout << 1 << '\n';
    }
    cout << a << '\n';
  }
  else {
    cout << -1 << '\n';
    return;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
