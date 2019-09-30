/* created   : 2019-09-23 23:52:16
 * accepted  : 2019-09-24 00:10:02
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  // 1101 1000 0010
  // 0110 0100 0010
  int n, m; cin >> n >> m;
  priority_queue<int> q;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    q.push(x);
  }
  // 1001 0101 0011 0001
  // 0100 0101 0011 0001
  while (m > 0) {
    int mx = q.top(); q.pop();
    bool ok = 0;
    for (int i = 31; i >= 0; i--) {
      if (mx & (1 << i)) {
        ok = 1;
        mx >>= 1;
        m--;
        q.push(mx);
        break;
      }
    }
    if (!ok) {
      break;
    }
  }
  ll ans = 0;
  while (!q.empty()) {
    ans += q.top(); q.pop();
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
