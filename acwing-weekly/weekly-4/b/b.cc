/* created   : 2021-07-29 07:02:25
 * accepted  : 2021-07-29 07:30:42
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

int dfs(ll len, ll n, ll k) {
  if (n == 0) return 0;
  if (n == 1) {
    assert(k == 1 && len == 1);
    return 1;
  }
  ll md = (len + 1) / 2;
  if (k == md) {
    return n;
  }
  else if (k > md) {
    return dfs(len / 2, n - 1, k - md);
  }
  else {
    return dfs(len / 2, n - 1, k);
  }
}

void solve() {
  // 1: 1
  // 2: 2*1 + 1 = 3 --> 2
  // 3: 2*3 + 1 = 7 --> 3
  // 4: 2*7 + 1 = 15 --> 4
  // 5: 2*15 + 1 = 31 --> 5
  // i: yi = 2**(i - 1) + yi-1
  ll N, K; cin >> N >> K;
  ll len = 1;
  for (int i = 1; i < N; i++) {
    len = 2 * len + 1;
  }
  trace(len);
  cout << dfs(len, N, K) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
