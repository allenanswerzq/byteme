/* created   : 2020-03-26 23:19:33
 * accepted  : 2020-03-27 22:06:35
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
#define xuyixuyi()
#endif
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  k--;
  vector<ll> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<ll> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  ll mx = a[k] + b[0];
  auto check = [&](int p) {
    int tail = n - 1;
    for (int i = p; i < n; i++) {
      if (i == k) continue;
      if (a[i] + b[tail] > mx) {
        return false;
      }
      tail--;
    }
    return true;
  };
  int lo = 0, hi = n - 1;
  while (lo + 1 < hi) {
    int md = lo + (hi - lo) / 2;
    if (check(md)) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  trace(lo, hi);
  cout << (check(lo) ? lo + 1 : hi + 1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
