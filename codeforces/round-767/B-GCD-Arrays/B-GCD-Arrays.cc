/* created   : 2022-02-15 22:57:56
 * accepted  : 2022-02-15 23:46:37
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // [2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18]
  // [3, 4, 5, 6]
  // [15, 4, 6]
  // [2,3,4]
  // [3,4,5]
  int L, R, K; cin >> L >> R >> K;
  if (L == R && L > 1) {
    cout << "YES\n";
    return;
  }
  int len = R - L + 1;
  int odd = 0;
  if (len % 2) {
    // [2, 3, 4]
    odd = len / 2 + (L % 2);
  }
  else {
    odd = len / 2;
  }
  // [3, 4]
  cout << (K >= odd ? "YES" : "NO") << "\n";
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
