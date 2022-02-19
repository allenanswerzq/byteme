/* created   : 2021-08-16 07:34:21
 * accepted  : 2021-08-16 07:51:53
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // ai - 1, ai - 2
  // 1, 2, 3
  // n * (n + 1) / 2
  // 1 3 5 7 9 ...
  //
  // n * n
  // 1 3 5 7 9 11 = 36 + 7
  //
  // 49 - 36
  // (n + 1) * (n + 1) - n^2 = 2*n + 1 = 13
  //
  // 1 2 3 4 5 6 7 ...
  int S; cin >> S;
  int i = 1;
  while (i * i < S) {
    i++;
  }
  cout << i << "\n";
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
