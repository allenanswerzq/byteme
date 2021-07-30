/* created   : 2021-07-30 08:24:42
 * accepted  : 2021-07-30 08:26:39
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  int odd = 0;
  int even = 0;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    if (x & 1) {
      odd++;
    }
    else {
      even++;
    }
  }
  bool ok = (odd > 0 && !even) || (even > 0 && !odd);
  cout << (ok ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
