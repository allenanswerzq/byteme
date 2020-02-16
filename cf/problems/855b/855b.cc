/* created   : 2020-02-16 21:54:40
 * accepted  : 2020-02-16 22:54:07
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
  ll n, p, q, r; cin >> n >> p >> q >> r;
  vector<ll> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  vector<ll> mi_left(n + 1);
  vector<ll> mx_left(n + 1);
  mi_left[0] = 1e9 + 7;
  mx_left[0] = -1e9 - 7;
  for (int i = 1; i <= n; i++) {
    mi_left[i] = min(mi_left[i - 1], a[i]);
    mx_left[i] = max(mx_left[i - 1], a[i]);
  }
  vector<ll> mi_right(n + 2);
  vector<ll> mx_right(n + 2);
  mi_right[n + 1] = 1e9 + 7;
  mx_right[n + 1] = -1e9 - 7;
  for (int i = n; i >= 1; i--) {
    mi_right[i] = min(mi_right[i + 1], a[i]);
    mx_right[i] = max(mx_right[i + 1], a[i]);
  }
  // -1000000000000000000
  trace(mi_left, mx_left);
  trace(mi_right, mx_right);
  ll ans = 0;
  bool first = true;
  for (int i = 1; i <= n; i++) {
    ll cur = a[i] * q;
    if (p < 0) {
      cur += mi_left[i] * p;
    }
    else {
      cur += mx_left[i] * p;
    }
    if (r < 0) {
      cur += mi_right[i] * r;
    }
    else {
      cur += mx_right[i] * r;
    }
    if (first) {
      first = false;
      ans = cur;
    }
    else {
      ans = max(ans, cur);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
