/* created   : 2021-09-06 07:34:13
 * accepted  : 2021-09-12 09:47:59
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  bool ok = true;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (i > 0 && A[i] < A[i - 1]) {
      ok = false;
    }
  }
  int ans = ok ? 0 : 100;
  if (A[0] == 1) {
    ans = min(ans, 1);
  }
  else if (A[0] < N) {
    ans = min(ans, 2);
  }
  else {
    ans = min(ans, 3);
  }
  if (A[N - 1] == N) {
    ans = min(ans, 1);
  }
  else if (A[N - 1] == 1) {
    ans = min(ans, 3);
  }
  else {
    ans = min(ans, 2);
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
