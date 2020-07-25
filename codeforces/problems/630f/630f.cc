/* created   : 2020-03-02 10:19:43
 * accepted  : 2020-03-02 11:01:29
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

template <class T>
struct CombinaSmall {
  vector<vector<T>> dp;

  // c(n, k) = c(n - 1, k) + c(n - 1, k - 1);
  explicit CombinaSmall(int n) {
    dp.resize(n + 1, vector<ll>(n + 1));
    for (int i = 0; i <= n; i++) {
      dp[i][0] = 1;
    }
    for (int i = 1; i <= n; i++) {
      for (int k = 1; k <= 7; k++) {
        dp[i][k] = dp[i - 1][k] + dp[i - 1][k - 1];
      }
    }
  }

  ll nck(int n, int k) { return (*this)(n, k); }

  ll operator()(int n, int k) { return dp[n][k]; }
};

void solve() {
  int n; cin >> n;
  ll ans = 0;
  CombinaSmall<ll> cs(n);
  for (int i = 5; i <= 7; i++) {
    ans += cs.nck(n, i);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
