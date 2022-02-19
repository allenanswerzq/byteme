/* created   : 2021-12-07 08:13:06
 * accepted  : 2021-12-08 08:14:24
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  vector<ll> pre(N);
  vector<ll> mi(N);
  int mo = 1e9, me = 1e9;
  ll so = 0, se = 0;
  for (int i = 0; i < N; i++) {
    int x; cin >> x;
    if (i & 1) {
      mo = min(mo, x);
      so += x;
      pre[i] = so;
      mi[i] = mo;
    }
    else {
      me = min(me, x);
      se += x;
      pre[i] = se;
      mi[i] = me;
    }
  }
  trace(pre);
  ll ans = 1e18;
  // 1 2 3
  for (int i = 1; i < N; i++) {
    int c = (i + 2) / 2;
    int e = (i + 1) / 2;
    trace(i, c, e);
    ll cur = mi[i] * (N - (c - 1)) + (pre[i] - mi[i]);
    cur += mi[i - 1] * (N - (e - 1)) + (pre[i - 1] - mi[i -1]);
    ans = min(ans, cur);
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
