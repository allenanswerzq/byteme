/* created   : 2020-11-02 17:21:58
 * accepted  : 2020-11-02 17:24:23
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N; cin >> N;
  vector<int> A(N);
  for (auto& a : A) cin >> a;
  ll sum = accumulate(all(A), 0ll);
  ll ans = 1e9;
  for (int i = 0; i < (1 << N); i++) {
    ll cur = 0;
    for (int j = 0; j < N; j++) {
      if ((i >> j) & 1) {
        cur += A[j];
      }
    }
    ans = min(ans, abs(cur - (sum - cur)));
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
