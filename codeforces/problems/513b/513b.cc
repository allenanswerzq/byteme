/* created   : 2020-03-09 21:24:51
 * accepted  : 2020-03-09 21:35:20
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
  ll n, m; cin >> n >> m;
  vector<int> ans(n + 1);
  int l = 1;
  int r = n;
  for (int i = 1; i < n; i++) {
    ll way = 1ll << (n - i - 1);
    trace(i, m, way);
    if (m <= way) {
      ans[l++] = i;
    }
    else {
      ans[r--] = i;
      m -= way;
    }
  }
  ans[r] = n;
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
