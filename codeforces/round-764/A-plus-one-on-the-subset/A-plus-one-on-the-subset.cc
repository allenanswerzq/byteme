/* created   : 2022-01-10 22:36:03
 * accepted  : 2022-01-10 22:45:46
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  int mx = 0;
  int mi = 1e9 + 7;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    mi = min(mi, x);
    mx = max(mx, x);
  }
  cout << mx - mi << "\n";
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
