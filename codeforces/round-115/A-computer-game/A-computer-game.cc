/* created   : 2022-01-09 15:18:07
 * accepted  : 2022-01-09 15:21:28
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<string> A(2);
  for (int i = 0; i < 2; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < N; i++) {
    if (A[0][i] == '1' && A[1][i] == '1') {
      cout << "NO\n";
      return;
    }
  }
  cout << "YES\n";
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
