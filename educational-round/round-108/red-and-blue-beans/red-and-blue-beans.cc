/* created   : 2021-10-24 10:42:54
 * accepted  : 2021-10-24 11:38:10
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int r, b, d; cin >> r >> b >> d;
  if (r < b) swap(r, b);
  // r1, r2, ... rb
  r -= b;
  if (r / b + (r % b != 0) <= d) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
  }
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
