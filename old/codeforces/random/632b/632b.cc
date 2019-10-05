/* created   : 2019-08-15 19:35:05
 * accepted  : 2019-08-15 21:50:37
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  string s;
  cin >> s;
  vector<ll> pr(n + 1);
  for (int i = 0; i < n; i++) {
    pr[i + 1] = pr[i] + (s[i] == 'B' ? a[i] : 0);
  }
  ll x = 0;
  pair<ll, int> fd = {0, -1};
  for (int i = 0; i < n; i++) {
    if (s[i] == 'A') {
      x += a[i];
    }
    if (x - pr[i + 1] > fd.x) {
      fd.x = x - pr[i + 1];
      fd.y = i;
    }
  }
  vector<ll> pk(n + 1);
  pair<ll, int> bk = {0, -1};
  for (int i = n - 1; i >= 0; i--) {
    pk[i] = pk[i + 1] + (s[i] == 'B' ? a[i] : 0);
  }
  x = 0;
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'A') {
      x += a[i];
    }
    if (x - pk[i] > bk.x) {
      bk.x = x - pk[i + 1];
      bk.y = i;
    }
  }
  trace(fd, bk);
  bool ok = 0;
  int p = fd.y;
  if (fd.x < bk.x) {
    ok = 1;
    p = bk.y - 1;
  }
  trace(ok, p);
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    if (i <= p) {
      ans += (s[i] == (ok ? 'B' : 'A') ? a[i] : 0);
    }
    else {
      ans += (s[i] == (ok ? 'A' : 'B') ? a[i] : 0);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
