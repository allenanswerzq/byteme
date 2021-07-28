/* created   : 2021-07-28 06:49:48
 * accepted  : 2021-07-28 07:04:54
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, K; cin >> N >> K;
  vector<int> A(N);
  for (int & a : A) {
    cin >> a;
  }
  int ans = 1e9;
  for (int i = 1; i <= 100; i++) {
    int cnt = 0;
    for (int j = 0; j < N; ) {
      if (A[j] == i) {
        while (j < N && A[j] == i) {
          j++;
        }
      }
      else {
        // If this position is not equals to `i`, put the
        // next K consective values into `i`.
        j += K;
        cnt++;
      }
    }
    trace(i, cnt);
    ans = min(ans, cnt);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve();
  }
  return 0;
}
