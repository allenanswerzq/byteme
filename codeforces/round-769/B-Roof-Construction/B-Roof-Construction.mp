/* created   : 2022-02-26 11:52:05
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve(int N) {
  // int N; cin >> N;
  vector<int> A(N);
  iota(all(A), 0);
  int ans = 1e9;
  vector<int> P;
  do {
    int cur = 0;
    for (int i = 0; i + 1 < N; i++) {
      cur = max(cur, A[i] ^ A[i + 1]);
    }
    if (cur < ans) {
      ans = cur;
      P = A;
    }
  } while (next_permutation(all(A)));
  iota(all(A), 0);
  do {
    int cur = 0;
    for (int i = 0; i + 1 < N; i++) {
      cur = max(cur, A[i] ^ A[i + 1]);
    }
    if (cur == ans) {
      trace(N, A);
    }
  } while (next_permutation(all(A)));
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= 10; i++) {
    // cout << "Case #" << i << ": ";
    solve(i);
  }
  return 0;
}
