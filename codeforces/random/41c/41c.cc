/* created   : 2019-08-18 15:24:20
 * accepted  : 2019-08-18 15:48:53
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
  string s;
  cin >> s;
  int p = s.find("at");
  string ans = string(120, 'z');
  while (p != -1) {
    string x = s;
    string cur;
    int n = x.size();
    bool at = 0;
    for (int i = 0; i < n; i++) {
      if (i && i != n - 3 && i + 3 <= n && x.substr(i, 3) == "dot") {
        cur += ".";
        i += 2;
      }
      else if (i && i != n - 2 && i == p) {
        cur += "@";
        i++;
        at = 1;
      }
      else {
        cur += x[i];
      }
    }
    if (at && (cur.size() < ans.size() || (cur.size() == ans.size() && cur < ans))) {
      ans = cur;
    }
    trace(p, cur);
    p = s.find("at", p + 2);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
