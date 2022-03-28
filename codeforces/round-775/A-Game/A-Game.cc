/* created   : 2022-03-27 21:39:00
 * accepted  : 2022-03-27 21:55:07
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // 10101111
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  int i = N - 1;
  while (i > 0 && A[i - 1] == A[i]) {
    i--;
  }
  int j = 0;
  while (j + 1 < N && A[j] == A[j + 1]) {
    j++;
  }
  cout << max(i - j, 0) << "\n";
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
