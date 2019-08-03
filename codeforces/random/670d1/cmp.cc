/*
 * creat   : 2019-07-18 11:29:06
 * accept  : 2019-07-18 12:17:31
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
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  ll lo = (1ll << 30);
  ll hi = (1ll << 32);
  for (int i = 0; i < n; ++i) {
    ll x = b[i] / a[i];
    lo = min(lo, x);
  }
  auto check = [&](ll md) {
    ll need = 0;
    for (int i = 0; i < n; ++i) {
      if (b[i] - md * a[i] < 0) {
        need += (ll) md * a[i] - b[i];
      }
      if (need > k) {
        return false;
      }
    }
    return need <= k;
  };
  while (hi - lo > 1) {
    ll md = lo + (hi - lo) / 2;
    if (check(md)) {
      lo = md;
    }
    else {
      hi = md;
    }
  }
  trace(lo, hi);
  cout << lo << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
