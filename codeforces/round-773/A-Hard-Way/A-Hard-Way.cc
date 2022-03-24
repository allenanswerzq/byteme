/* created   : 2022-03-23 09:56:12
 * accepted  : 2022-03-23 10:04:02
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  vector<ar> A(3);
  for (int i = 0; i < 3; i++) {
    cin >> A[i][1] >> A[i][0];
  }
  sort(all(A));
  if (A[1][0] == A[2][0] && A[0][0] < A[1][0]) {
    cout << abs(A[1][1] - A[2][1]) << "\n";
    return;
  }
  cout << "0" << "\n";
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
