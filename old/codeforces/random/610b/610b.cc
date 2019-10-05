//=============================================================
// Name        : 610b
// Date        : Mon Jun 24 23:09:23 CST 2019
// Accepted    : Mon Jun 24 23:41:04 CST 2019
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

template<class T> inline void amin(T &x, const T &y) { if (y < x) x = y; }

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> mi(n);
  mi[n - 1] = {a[n - 1], n - 1};
  for (int i = n - 2; i >= 0; --i) {
    mi[i] = {a[i], i};
    amin(mi[i], mi[i + 1]);
  }
  trace(mi);
  ll ans = 0;
  for (int i = 0; i < n; ++i) {
    ll tmp = (n - i);
    pair<int, int> p = {mi[i].first - 1, mi[i].second};
    amin(p, mi[0]);
    tmp += p.first * 1ll * n + (p.second - 0);
    trace(i, tmp);
    ans = max(tmp, ans);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
