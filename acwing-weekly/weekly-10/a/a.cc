/* created   : 2021-08-08 13:38:24
 * accepted  : 2021-08-08 13:47:39
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int A, B; cin >> A >> B;
  if (A % B == 0) {
    cout << 0 << "\n";
  }
  else {
    // 10 % 4 == 2
    // a = k * b + x
    // a + b - x = k * b + b
    cout << (B - A % B) << "\n";
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
