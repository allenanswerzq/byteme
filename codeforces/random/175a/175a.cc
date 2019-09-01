/* created   : 2019-08-18 20:34:14
 * accepted  : 2019-08-18 21:01:24
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

bool check(string& a) {
  int n = a.size();
  if (n == 0) {
    return false;
  }
  else if (n > 1 && a[0] == '0') {
    return false;
  }
  else if (n > 7) {
    return false;
  }
  return true;
}

void solve() {
  string a;
  cin >> a;
  int n = a.size();
  ll ans = -1;
  const int INF = 1e6;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      string s1 = a.substr(0, i);
      string s2 = a.substr(i, j - i);
      string s3 = a.substr(j);
      trace(s1, s2, s3);
      if (check(s1) && check(s2) && check(s3)) {
        ll x1 = stoll(s1);
        ll x2 = stoll(s2);
        ll x3 = stoll(s3);
        if (x1 > INF || x2 > INF || x3 > INF) {
          continue;
        }
        ans = max(ans, x1 + x2 + x3);
      }
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
