/* created   : 2019-09-21 23:20:57
 * accepted  : 2019-09-22 14:23:05
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
  string s; cin >> s;
  int n = s.size();
  bool seen_two = false;
  int one = 0;
  int zero = 0;
  int last = 0;
  for (int i = 0; i < n; i++) {
    if (!seen_two && s[i] == '0') {
      zero++;
      last = i;
    }
    if (s[i] == '1') {
      one++;
    }
    if (s[i] == '2') {
      seen_two = true;
    }
  }
  string ans = string(zero, '0');
  ans += string(one, '1');
  trace(ans, s);
  for (int i = 0; i < n; i++) {
    if (s[i] == '2') {
      ans += s[i];
    }
    else if (s[i] == '0' && i > last) {
      ans += s[i];
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
