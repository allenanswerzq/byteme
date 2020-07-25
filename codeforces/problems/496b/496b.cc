/* created   : 2020-02-24 16:47:53
 * accepted  : 2020-02-24 17:00:42
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
  int n; cin >> n;
  string s; cin >> s;
  string mi = s;
  for (int i = 0; i < n; i++) {
    string t = s;
    if (s[i] != '0') {
      int step = 10 - (s[i] - '0');
      for (int j = 0; j < n; j++) {
        char ch = ((s[j] - '0' + step) % 10 + '0');
        t[j] = ch;
      }
      trace(i, step, t);
    }
    assert(t[i] == '0');
    string cur = t.substr(i) + t.substr(0, i);
    trace(i, cur, mi);
    if (cur < mi) {
      mi = cur;
    }
  }
  cout << mi << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
