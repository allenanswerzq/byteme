/* created   : 2021-12-01 07:52:53
 * accepted  : 2021-12-01 07:59:08
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, K1, K2; cin >> N >> K1 >> K2;
  int W, B; cin >> W >> B;
  int K3 = N - K1;
  int K4 = N - K2;
  int w = min(K1, K2) + (max(K1, K2) - min(K1, K2)) / 2;
  int b = min(K3, K4) + (max(K3, K4) - min(K3, K4)) / 2;
  trace(w, b);
  cout << ((w >= W && b >= B) ? "YES" : "NO") << "\n";
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
