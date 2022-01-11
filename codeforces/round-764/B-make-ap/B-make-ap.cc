/* created   : 2022-01-10 22:47:47
 * accepted  : 2022-01-10 22:54:39
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  ll a, b, c; cin >> a >> b >> c;
  // m * a -> b -> c
  ll d = c - b;
  if ((b - d) % a == 0 && (b - d) / a > 0) {
    // b - m * a = d
    cout << "YES\n";
    return;
  }
  // a -> m * b -> c
  d = c - a;
  if (d % 2 == 0 && (d / 2 + a) % b == 0 && (d / 2 + a) / b > 0) {
    // m * b - a = d / 2
    cout << "YES\n";
    return;
  }
  // a -> b -> m * c
  d = b - a;
  if ((b + d) % c == 0 && (b + d) / c > 0) {
    // m * c - b = d
    cout << "YES\n";
    return;
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
