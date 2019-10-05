/*
 * created   : 2019-07-30 21:43:43
 * accepted  : 2019-07-30 22:05:10
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
  int a, b, c;
  cin >> a >> b >> c;
  int m;
  cin >> m;
  vector<int> usb, ps;
  for (int i = 0; i < m; i++) {
    int x;
    string y;
    cin >> x >> y;
    if (y == "USB") {
      usb.push_back(x);
    }
    else {
      ps.push_back(x);
    }
  }
  sort(usb.begin(), usb.end());
  sort(ps.begin(), ps.end());
  int nu = (int) usb.size();
  int np = (int) ps.size();
  int p = min(a, nu);
  int q = min(b, np);
  ll ans = accumulate(usb.begin(), usb.begin() + p, 0ll);
  ans += accumulate(ps.begin(), ps.begin() + q, 0ll);
  while ((p < nu || q < np) && c-- > 0) {
    const int inf = 1e9 + 7;
    int ma = inf;
    int mb = inf;
    if (p < nu) {
      ma = usb[p];
    }
    if (q < np) {
      mb = ps[q];
    }
    assert(ma != inf || mb != inf);
    if (ma < mb) {
      ans += ma;
      p++;
    }
    else {
      ans += mb;
      q++;
    }
  }
  cout << p + q << " " << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
