/* created   : 2020-02-03 09:08:16
 * accepted  : 2020-02-03 09:29:40
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
  int n; cin >> n;
  ll s = 0;
  ll x = 0;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    s += a;
    x ^= a;
  }
  cout << 2 << '\n';
  cout << x << ' ' << s + x << '\n';
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
