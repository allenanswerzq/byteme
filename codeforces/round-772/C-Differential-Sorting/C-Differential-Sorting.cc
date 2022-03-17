/* created   : 2022-03-17 20:09:18
 * accepted  : 2022-03-17 20:56:39
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
  // ------xyz
  int i = N - 2;
  bool ok = false;
  while (i >= 0 && A[i] <= A[i + 1]) {
    if (A[i + 1] >= 0) {
      ok = true;
      break;
    }
    i--;
  }
  if (i == -1) {
    cout << 0 << "\n";
    return;
  }
  if (!ok) {
    cout << -1 << "\n";
    return;
  }
  // ai <= ai+1 <= ...
  //
  cout << i << "\n";
  for (int j = 0; j < i; j++) {
    cout << j + 1 << " " << i + 1 << " " << i + 2 << "\n";
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
