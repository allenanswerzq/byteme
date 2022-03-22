/* created   : 2022-03-21 22:17:38
 * accepted  : 2022-03-22 21:19:11
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // 10 2
  //-6 -1 -2 4 -6 -1 -4 4 -5 -4
  //    1  0 6
  //    ------
  //
  int N, X; cin >> N >> X;
  vector<int> A(N);
  vector<ll> pre(N + 1);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    pre[i + 1] = pre[i] + A[i];
  }
  const int INF = 1e9;
  vector<ll> mx(N + 1, -INF);
  for (int len = 0; len <= N; len++) {
    ll cur = -INF;
    for (int i = 0; i + len <= N; i++) {
      // [i, i + len - 1]
      cur = max(cur, pre[i + len] - pre[i]);
    }
    mx[len] = cur;
  }
  trace(mx);
  for (int k = 0; k <= N; k++) {
    ll cur = 0;
    for (int len = 0; len <= N; len++) {
      cur = max(cur, mx[len] + min(k, len) * X);
    }
    cout << cur << (k == N ? '\n' : ' ');
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
