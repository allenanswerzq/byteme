/* created   : 2022-03-06 23:26:02
 * accepted  : 2022-03-06 23:35:23
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  string S; cin >> S;
  int one = 0;
  for (char c : S) {
    one += (c == '1');
  }
  int n = S.size();
  if (one == n - one) {
    cout << one - 1 << "\n";
  }
  else {
    cout << min(one, n - one) << "\n";
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
