/* created   : 2022-03-27 22:00:46
 * accepted  : 2022-03-28 18:34:28
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  ll sum = 0;
  ll mx = 0;
  for (int i = 0; i < N; i++) {
    ll x; cin >> x;
    sum += x;
    mx = max(mx, x);
  }
  sum -= mx;
  if (mx == 0) {
    cout << 0 << "\n";
  }
  else if (sum >= mx) {
    // -m-m--m
    cout << 1 << "\n";
  }
  else {
    // -m--m-
    // m-
    // m-
    cout << mx - sum << "\n";
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
