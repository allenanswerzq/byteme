/* created   : 2021-08-05 08:25:33
 * accepted  : 2021-08-05 08:27:47
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, A, B, C; cin >> N >> A >> B >> C;
  string S; cin >> S;
  int ans = 0;
  for (char c : S) {
    if (c == '0') {
      ans += min(A, C + B);
    }
    else {
      ans += min(B, C + A);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
