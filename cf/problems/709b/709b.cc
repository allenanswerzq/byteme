/* created   : 2020-03-01 16:54:56
 * accepted  : 2020-03-01 18:11:49
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
  int n, start; cin >> n >> start;
  if (n == 1) {
    cout << 0 << '\n';
    return;
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  ll ans = 1e18 + 7;
  for (int i = 0; i < n; i++) {
    ll lo = (i == 0 ? a[1] : a[0]);
    ll hi = (i == n - 1 ? a[n - 2] : a[n - 1]);
    assert(lo <= hi);
    if (start < lo) {
      ans = min(ans, hi - start);
    }
    else if (lo <= start && start <= hi) {
      ll mi = min(abs(lo - start), abs(hi - start));
      ans = min(ans, hi - lo + mi);
    }
    else {
      ans = min(ans, start - lo);
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
