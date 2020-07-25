/* created   : 2019-10-10 23:52:18
 * accepted  : 2019-10-11 00:40:42
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
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> b = a;
  sort(b.begin(), b.end());
  b.erase(unique(b.begin(), b.end()), b.end());
  for (int i = 0; i < n; i++) {
    a[i] = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
  }
  int ans = 1 << 30;
  for (int lo = 0; lo <= n; lo++) {
    vector<int> use(n);
    bool ok = true;
    for (int i = 0; i < lo; i++) {
      if (use[a[i]]) {
        ok = false;
        break;
      }
      use[a[i]] = 1;
    }
    if (!ok) {
      continue;
    }
    int hi = n - 1;
    for (; hi > lo; hi--) {
      if (use[a[hi]]) {
        break;
      }
      use[a[hi]] = 1;
    }
    ans = min(ans, hi - lo + 1);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
