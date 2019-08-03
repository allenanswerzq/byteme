/*
 * created   : 2019-07-24 22:26:07
 * accepted  : 2019-07-24 22:34:53
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  int lo = 0;
  int hi = 0;
  map<int, int> mp;
  for (int i = 0; i < n; ++i) {
    char op;
    int id;
    cin >> op >> id;
    if (op == 'L') {
      mp[id] = lo;
      lo--;
      if (i == 0) {
        hi++;
      }
    }
    else if (op == 'R') {
      mp[id] = hi;
      hi++;
      if (i == 0) {
        lo--;
      }
    } else {
      int ans = max(min(mp[id] - lo - 1, hi - mp[id] - 1), 0);
      cout << ans << "\n";
    }
  }
  trace(mp);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
