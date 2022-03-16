/* created   : 2022-03-15 21:40:26
 * accepted  : 2022-03-16 10:19:02
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int mx = 0;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    if (A[i] > mx) {
      // if no values greater than x
      // -----x
      if (mx == i) {
        ans++;
        mx = 0;
      }
    }
    mx = max(mx, A[i]);
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
