/* created   : 2021-08-28 15:52:09
 * accepted  : 2021-08-28 15:54:24
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  vector<int> A(4);
  for (int i = 0; i < 4; i++) {
    cin >> A[i];
  }
  int a = max(A[0], A[1]);
  int b = max(A[2], A[3]);
  sort(all(A));
  if (A[3] == max(a, b) && A[2] == min(a, b)) {
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
