/* created   : 2021-08-12 08:01:48
 * accepted  : 2021-08-13 21:18:57
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  ll N; cin >> N;
  if (N <= 6) {
    cout << 15 << "\n";
  }
  else {
    cout << (N + 1) / 2 * 5 << "\n";
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
