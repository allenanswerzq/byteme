/* created   : 2022-02-20 18:55:57
 * accepted  : 2022-02-21 23:00:41
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  //
  // 1 2 2 | 2
  //
  // 5 5 5 1 | 5 5 1 | 5 5 5 1
  // [x, y]
  //
  int N, K; cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  auto check = [&](int x, int y) {
    int cnt = 0;
    // -1 -1 1 1 1
    // -1 -2 -1 0 1 2 3 4
    for (int j = 0; j < N; j++) {
      if (x <= A[j] && A[j] <= y) {
        cnt++;
      }
      else {
        cnt--;
      }
    }
    // trace(x, y, cnt);
    return cnt > 0;
  };
  trace(A, K);
  int mi = 1e9;
  ar ans = {0, 0};
  for (int x = 1; x <= N; x++) {
    int lo = x - 1;
    int hi = N + 1;
    while (lo + 1 < hi) {
      int md = lo + (hi - lo) / 2;
      // trace(x, md, check(x, md));
      if (check(x, md)) {
        hi = md;
      }
      else {
        lo = md;
      }
    }
    if (hi != N + 1 && mi > hi - x) {
      trace(x, lo, hi);
      ans = {x, hi};
      mi = hi - x;
    }
  }
  cout << ans[0] << " " << ans[1] << "\n";
  // for (int i = 1; i <= K - 1; i++) {
  //   cout << i << " " << i << "\n";
  // }
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
