/* created   : 2022-03-11 20:34:44
 * accepted  : 2022-03-11 23:23:41
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  ll N, X, Y; cin >> N >> X >> Y;
  // for a+b, a^b, the last bit must be the same
  int t = (X & 1);
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    t ^= (x & 1);
  }
  if (t == (Y & 1)) {
    cout << "Alice\n";
  }
  else {
    cout << "Bob\n";
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
