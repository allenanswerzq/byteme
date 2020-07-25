/* created   : 2020-02-04 14:56:58
 * accepted  : 2020-02-04 15:52:06
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

void solve() {
  int a, b; cin >> a >> b;
  if (a == b) {
    cout << 0 << '\n';
    return;
  }
  ll step = 0;
  ll d = abs(a - b);
  for (int step = 1; ; step++) {
    ll s = step * (step + 1) / 2;
    ll x = s - a + b;
    if (x >= 0 && x % 2 == 0 && x / 2 + a - b >= 0) {
      cout << step << '\n';
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
