/*
 * created   : 2019-07-25 17:31:15
 * accepted  : 2019-07-25 17:37:56
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> a(n), b(m);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  ll ans = 1e18;
  for (int i = 0; i < n; ++i) {
    ll cur = -1e18;
    for (int j = 0; j < n; ++j) {
      if (j != i) {
        for (int k = 0; k < m; ++k) {
          cur = max(cur, (ll) b[k] * a[j]);
        }
      }
    }
    ans = min(ans, cur);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
