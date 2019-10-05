/* created   : 2019-09-15 13:18:41
 * accepted  : 2019-09-15 16:17:00
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

int n, s;
vector<ll> v;

bool check(int md) {
  vector<ll> t = v;
  for (int i = 0; i < n; i++) {
    t[i] += (i + 1) * (ll) md;
  }
  sort(t.begin(), t.end());
  ll val = 0;
  for (int i = 0; i < md; i++) {
    val += t[i];
    if (val > s) {
      return false;
    }
  }
  return true;
}

void solve() {
  cin >> n >> s;
  v.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int lo = -1;
  int hi = n + 1;
  while (hi - lo > 1) {
    int md = lo + (hi - lo) / 2;
    trace(lo, hi, md);
    if (check(md)) {
      lo = md;
    }
    else {
      hi = md;
    }
  }
  for (int i = 0; i < n; i++) {
    v[i] += (i + 1) * (ll) lo;
  }
  sort(v.begin(), v.end());
  ll ans = 0;
  for (int i = 0; i < lo; i++) {
    ans += v[i];
  }
  cout << lo << ' ' << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
