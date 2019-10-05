//=============================================================
// Name        : 810b
// Date        : Wed Jun 19 10:03:24 CST 2019
// Accepted    : Wed Jun 19 10:36:35 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<pair<ll, ll>> a(n), order(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].first >> a[i].second;
    ll extra = min(2 * a[i].first, a[i].second) - min(a[i].first, a[i].second);
    order.emplace_back(extra, i);
  }
  sort(order.rbegin(), order.rend());
  trace(order);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    int ix = order[i].second;
    trace(a[ix], ans);
    if (i < m) {
      ans += min(2 * a[ix].first, a[ix].second);
    } else {
      ans += min(a[ix].first, a[ix].second);
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
