/* created   : 2019-10-28 23:57:16
 * accepted  : 2019-10-29 00:16:18
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

// 3 < 5
// 4 < 8
max(3 * 4, 5 * 8)

vector<int> a;
vector<int> b;
int n;
ll k;

bool check(ll md) {
  ll cnt = 0;
  for (int i = 0; i < n; i++) {
    if ((ll) a[i] * b[i] > md) {
      cnt += a[i] - md / b[i];
    }
  }
  return cnt <= k;
}

void solve() {
  cin >> n >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  b.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end(), greater<int>());
  ll mx = 0;
  for (int i = 0; i < n; i++) {
    mx = max(mx, (ll) a[i] * b[i]);
  }
  ll lo = 0;
  ll hi = mx;
  while (lo + 1 < hi) {
    ll md = lo + (hi - lo) / 2;
    if (check(md)) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  trace(lo, hi, check(lo));
  cout << (check(lo) ? lo : hi) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
