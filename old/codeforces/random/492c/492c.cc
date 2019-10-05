/*
 * Creat   : Mon Jul 15 10:00:18 CST 2019
 * Accept  : Mon Jul 15 10:40:38 CST 2019
 * Author  : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  ll n, r, g;
  cin >> n >> r >> g;
  vector<pair<int, int>> a(n);
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x >> a[i].y;
    sum += a[i].x;
  }
  typedef pair<int, int> pii;
  sort(a.begin(), a.end(), [](pii& x, pii& y) {
    return x.y < y.y;
  });
  trace(a);
  ll extra = n * g - sum;
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    if (extra > 0 && a[i].x < r) {
      ans += min(extra, r - a[i].x) * a[i].y;
      extra -= min(extra, r - a[i].x);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
