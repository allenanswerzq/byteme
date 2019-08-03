/*
 * creat   : 2019-07-16 19:05:17
 * accept  : 2019-07-16 19:56:59
 * author  : landcold7
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
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x;
  }
  for (int i = 0; i < n; ++i) {
    cin >> a[i].y;
  }
  const int inf = (1 << 30);
  ll ans = (1ll << 61);
  for (int j = 1; j < n - 1; ++j) {
    int mi = inf;
    for (int i = 0; i < j; ++i) {
      if (a[i].x < a[j].x) {
        mi = min(mi, a[i].y);
      }
    }
    int mk = inf;
    for (int k = j + 1; k < n; ++k) {
      if (a[j].x < a[k].x) {
        mk = min(mk, a[k].y);
      }
    }
    if (mi != inf && mk != inf) {
      ans = min(ans, (ll) mi + mk + a[j].y);
    }
  }
  cout << (ans == (1ll << 61) ? -1 : ans) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
