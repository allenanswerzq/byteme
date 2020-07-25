/* created   : 2020-02-17 09:47:27
 * accepted  : 2020-02-17 10:23:52
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

struct Compare {
  int operator()(const pair<ll, ll>& a, const pair<ll, ll>& b) {
    return a.x < b.x;
  }
};

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> b(m);
  for (int i = 0; i < m; i++) {
    cin >> b[i];
  }
  auto check = [&](int r) {
    vector<pair<ll, ll>> v;
    for (int i = 0; i < m; i++) {
      v.push_back({b[i] - r, b[i] + r});
    }
    sort(all(b));
    // trace(r, b, v);
    for (int i = 0; i < n; i++) {
      Compare comp;
      int p = upper_bound(all(v), make_pair(a[i], (ll) 3e9 + 7), comp) - v.begin();
      // trace(a[i], p);
      if (p > 0) {
        if (!(v[p - 1].x <= a[i] && a[i] <= v[p - 1].y)) {
          return false;
        }
      }
      else {
        return false;
      }
    }
    return true;
  };
  int lo = -1;
  int hi = 2e9 + 7;
  while (lo + 1 < hi) {
    int md = lo + (hi - lo) / 2;
    if (check(md)) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  bool verify = check(lo) | check(hi);
  assert(verify);
  cout << (check(lo) ? lo : hi) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
