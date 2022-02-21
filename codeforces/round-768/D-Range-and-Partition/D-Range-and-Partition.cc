/* created   : 2022-02-20 18:55:57
 * accepted  : 2022-02-22 05:00:16
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, K; cin >> N >> K;
  vector<int> A(N);
  vector<int> B(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    B[i] = A[i];
  }
  sort(all(B));
  auto check = [&](int x, int y) {
    // int cnt = 0;
    // for (int j = 0; j < N; j++) {
    //   if (x <= A[j] && A[j] <= y) {
    //     cnt++;
    //   }
    //   else {
    //     cnt--;
    //   }
    // }
    // greedy: the number of elements inside the range [x, y] - outside
    // of range must >= K, so that we can split the array into K subarrays.
    int in = upper_bound(all(B), y) - lower_bound(all(B), x);
    int out = N - in;
    return in - out >= K;
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
  int cnt = 0;
  int pos = 0;
  for (int i = 0; i < N; i++) {
    if (ans[0] <= A[i] && A[i] <= ans[1]) {
      cnt++;
    }
    else {
      cnt--;
    }
    if (cnt > 0 && K--) {
      cout << pos + 1 << " " << (K == 0 ? N : i + 1) << "\n";
      cnt = 0;
      pos = i + 1;
      if (K == 0) break;
    }
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
