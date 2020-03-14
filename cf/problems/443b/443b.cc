/* created   : 2020-03-13 23:33:44
 * accepted  : 2020-03-14 00:01:38
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
typedef pair<int, int> pii;

void solve() {
  string s; cin >> s;
  int k; cin >> k;
  s += string(k, '#');
  int n = s.size();
  int ans = 0;
  for (int x = n / 2; x >= 1; x--) {
    for (int i = 0; i + 2 * x <= n; i++) {
      bool ok = true;
      for (int j = i; j < i + x; j++) {
        if (!(s[j] == s[j + x] || s[j] == '#' || s[j + x] == '#')) {
          // trace(j, s[j], s[j + x]);
          ok = false;
          break;
        }
      }
      // trace(s, x, i, ok);
      if (ok) {
        ans = max(ans, x);
      }
    }
  }
  cout << ans * 2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
