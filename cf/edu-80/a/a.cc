/* created   : 2020-01-14 22:35:14
 * accepted  : 2020-01-14 22:44:07
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
  int n, d; cin >> n >> d;
  for (int x = 0; x < 1e6; x++) {
    int t = x + 1;
    // trace(x, n, d);
    if (x + (d + t - 1) / t <= n) {
      cout << "YES" << '\n';
      return;
    }
  }
  cout << "NO" << '\n';
  return;
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
