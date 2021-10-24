/* created   : 2021-10-24 11:50:24
 * accepted  : 2021-10-24 13:07:47
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, M, K; cin >> N >> M >> K;
  // 1 1 1  1 2 3
  // 2 2 2  1 2 3
  if (N * M - 1 == K) {
    cout << "YES\n";
  }
  else {
    cout << "NO\n";
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
