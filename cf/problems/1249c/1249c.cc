/* created   : 2020-02-04 16:12:30
 * accepted  : 2020-02-04 19:13:46
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

vector<int> f(ll x) {
  vector<int> ret;
  while (x) {
    ret.push_back(x % 3);
    x /= 3;
  }
  return ret;
}

ll po(int x, int q) {
  ll ret = 1;
  for (int i = 1; i <= q; i++) {
    ret *= x;
  }
  return ret;
}

void solve() {
  ll n; cin >> n;
  vector<int> r = f(n);
  int p = -1;
  int m = r.size();
  for (int i = 0; i < m; i++) {
    if (r[i] == 2) {
      p = i;
    }
  }
  if (p == -1) {
    cout << n << '\n';
    return;
  }
  int q = -1;
  for (int i = p + 1; i <= m; i++) {
    if (i == m || r[i] == 0) {
      q = i;
      break;
    }
  }
  ll ans = 0;
  for (int i = q + 1; i < m; i++) {
    ans += r[i] * po(3, i);
  }
  trace(n, ans, p, q, r);
  cout << ans + po(3, q) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
