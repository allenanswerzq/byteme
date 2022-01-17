/* created   : 2022-01-17 08:43:06
 * accepted  : 2022-01-17 08:49:29
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // 10010
  // 01001
  // 10101
  int N, M; cin >> N >> M;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int ans = 0;
  for (int i = M - 1; i >= 0; i--) {
    int one = 0;
    for (int a : A) {
      one += (a >> i) & 1;
    }
    if (one > N - one) {
      ans |= (1 << i);
    }
  }
  cout << ans << "\n";
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
