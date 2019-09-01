/* created   : 2019-08-11 16:53:30
 * accepted  : 2019-08-11 17:04:31
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
  int n, m;
  cin >> n >> m;
  vector<int> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    a[i]--;
  }
  int mi = (1 << 30);
  int ix = -1;
  for (int i = 0; i < n; i++) {
    int cur = 0;
    for (int j = 0; j < m; j++) {
      int x = (a[j] - i + n) % n;
      cur += min(x, n - x);
    }
    if (cur < mi) {
      mi = cur;
      ix = i;
    }
  }
  trace(ix);
  ll ans = 0;
  for (int i = 0; i < m; i++) {
    int x = (a[i] - ix + n) % n;
    ans += min(x, n - x);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
