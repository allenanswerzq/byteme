/* created   : 2021-07-30 08:29:49
 * accepted  : 2021-07-31 09:01:50
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, K; cin >> N >> K;
  vector<int> cnt(100);
  for (int i = 0; i < N; i++) {
    ll x; cin >> x;
    // 123
    // 10^2 + 2*10^1 + 3*10
    for (int j = 0; x > 0; j++) {
      cnt[j] += x % K;
      x /= K;
    }
  }
  for (int c : cnt) {
    if (c > 1) {
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
