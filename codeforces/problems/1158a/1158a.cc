/* created   : 2020-02-24 10:50:11
 * accepted  : 2020-02-24 16:22:54
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

void solve() {
  int n, m; cin >> n >> m;
  vector<int> b(n);
  int mi = 1e9 + 7;
  for (int i = 0; i < n; i++) {
    cin >> b[i];
    mi = min(mi, b[i]);
  }
  vector<int> g(m);
  for (int i = 0; i < m; i++) {
    cin >> g[i];
  }
  sort(all(g));
  for (int i = 0; i < n; i++) {
    int lo = lower_bound(all(g), b[i]) - g.begin();
    if (lo != 0) {
      cout << -1 << '\n';
      return;
    }
  }
  sort(all(b));
  ll ans = 0;
  bool ok = (b[n - 1] == g[0]);
  trace(ok, b, g);
  for (int i = 0; i < n; i++) {
    if (i == n - 1) {
      if (ok) {
        ans += accumulate(all(g), 0ll);
        ok = true;
      }
      else {
        ans += b[i] + accumulate(all(g), 0ll) - g[0];
      }
    }
    else if (i == n - 2) {
      if (ok) {
        ans += m * 1ll * b[i];
      }
      else {
        ans += (m - 1) * 1ll * b[i] + g[0];
      }
    }
    else {
      ans += m * 1ll * b[i];
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
