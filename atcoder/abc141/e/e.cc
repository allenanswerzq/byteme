/* created   : 2019-09-24 00:14:34
 * accepted  : 2019-09-24 00:25:56
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

int n;
string s;

bool check(int md) {
  for (int i = 0; i + md <= n; i++) {
    string x = s.substr(i, md);
    // This can pass
    // TODO(zq7)
    if ((int) s.find(x, i + md) != -1) {
      return true;
    }
    // However this part below can not
    // for (int j = i + md; j + md <= n; j++) {
    //   string y = s.substr(j, md);
    //   if (x == y) {
    //     return true;
    //   }
    // }
  }
  return false;
}

void solve() {
  cin >> n >> s;
  int lo = -1;
  int hi = n + 1;
  trace(lo, hi);
  while (hi - lo > 1) {
    int md = lo + (hi - lo) / 2;
    if (check(md)) {
      lo = md;
    }
    else {
      hi = md;
    }
  }
  cout << lo << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
