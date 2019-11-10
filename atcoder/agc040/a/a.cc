/* created   : 2019-11-05 23:16:49
 * accepted  : 2019-11-06 10:21:25
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

void solve() {
  string s; cin >> s;
  int n = s.size();
  vector<int> a(n + 1);
  for (int i = 0; i < n; i++) {
    if (s[i] == '<') {
      a[i + 1] = max(a[i + 1], a[i] + 1);
    }
  }
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == '>') {
      a[i] = max(a[i], a[i + 1] + 1);
    }
  }
  trace(s, n, a);
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    ans += a[i];
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
