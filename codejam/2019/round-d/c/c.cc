/* created   : 2019-07-28 14:13:48
 * accepted  : 2019-07-28 14:33:11
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

void solve(int tc) {
  int k, n; cin >> k >> n;
  vector<pair<ll, ll>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].y;
  }
  for (int i = 0; i < n; i++) {
    cin >> a[i].x;
  }
  trace(a);
  cout << "Case #" << tc << ": ";
  ll ans = 1e18 + 7;
  for (int i = 0; i < n; i++) {
    auto p = a[i];
    vector<pair<ll, ll>> b = a;
    for (int j = 0; j < n; ++j) {
      b[j].x += abs(p.y - b[j].y);
    }
    sort(b.begin(), b.end());
    ll tmp = p.x;
    int cnt = 0;
    for (int j = 0; j < n && cnt < k; j++) {
      if (b[j].y != p.y) {
        tmp += b[j].x;
        cnt++;
      }
    }
    trace(b, tmp, ans);
    ans = min(ans, tmp);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; ++i) {
    solve(i);
  }
  return 0;
}
