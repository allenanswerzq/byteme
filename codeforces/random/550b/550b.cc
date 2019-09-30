/* created   : 2019-09-06 23:57:18
 * accepted  : 2019-09-07 00:01:51
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
  int n, l, r, x;
  cin >> n >> l >> r >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 0; i < (1 << n); i++) {
    int cnt = 0;
    int score = 0;
    int mx = 0;
    int mi = 1 << 30;
    for (int j = 0; j < 32; j++) {
      if (i & (1ll << j)) {
        cnt++;
        score += a[j];
        mx = max(mx, a[j]);
        mi = min(mi, a[j]);
      }
    }
    if (cnt >= 2 && l <= score && score <= r && mx - mi >= x) {
      ans++;
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
