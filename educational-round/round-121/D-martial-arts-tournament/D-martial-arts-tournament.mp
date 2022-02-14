/* created   : 2022-02-15 08:23:12
 * accepted  : $ACCEPTED
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
  ll ans = 1e18;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int p = upper_bound(all(A), A[i]) - A.begin();
      int c = upper_bound(all(A), A[j]) - A.begin();
      ll cur = ceil_pow2(p) - p;
      cur += ceil_pow2(c - p) - (c - p);
      cur += ceil_pow2(N - c) - (N - c);
      ans = min(ans, cur);
      // trace(p, c, ans, A);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int t; cin >> t;
  for (int i = 1; i <= t; i++) {
    solve();
  }
  return 0;
}
