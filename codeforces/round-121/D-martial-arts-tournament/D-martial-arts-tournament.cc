/* created   : 2022-02-14 23:04:18
 * accepted  : 2022-02-15 09:07:31
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

int ceil_pow2(int x) {
  int ans = 1;
  while (ans < x) {
    ans *= 2;
  }
  return ans;
}

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(all(A));
  trace(A);
  ll ans = 1e18;
  for (int i = 0; i <= N; i++) {
    int p = i == N ? 0 : upper_bound(all(A), A[i]) - A.begin();
    // [0...][p...][c..N-1]
    // case: 0
    ll cur = ceil_pow2(p) - p;
    cur += ceil_pow2(N - p) - (N - p);
    cur += 1;
    ans = min(ans, cur);
    trace(p, cur, ans);
    // case: 1, 2, 4, 8
    for (int j = 1; p + j - 1 < N; j *= 2) {
      // [p...p+j-1] length if power of 2
      int v = A[p + j - 1];
      int c = upper_bound(all(A), v) - A.begin();
      if (c - p > j) {
        int x = lower_bound(all(A), v) - A.begin();
        if (x > 0) {
          c = upper_bound(all(A), A[x - 1]) - A.begin();
        }
      }
      cur = ceil_pow2(p) - p;
      cur += ceil_pow2(c - p) - (c - p);
      cur += ceil_pow2(N - c) - (N - c);
      ans = min(ans, cur);
      // trace(j, p, c, ans, v);
    }
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
