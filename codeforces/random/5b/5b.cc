/* created   : 2019-08-10 22:06:46
 * accepted  : 2019-08-10 23:52:57
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
  vector<string> a;
  string s;
  int mx = 0;
  while (getline(cin, s)) {
    a.push_back(s);
    mx = max(mx, (int) s.size());
  }
  trace(a, mx);
  int n = (int) a.size();
  mx += 2;
  vector<string> ans(n + 2, string(mx, '*'));
  trace(ans);
  int turn = 0;
  for (int i = 0; i < n; i++) {
    int x = a[i].size();
    int t = -1;
    int d = mx - x - 2;
    if (d % 2) {
      t = !turn ? d / 2 : (d + 1) / 2;
      turn ^= 1;
    }
    else {
      t = d / 2;
    }
    for (int j = 0; j < x; j++) {
      ans[i + 1][t + j + 1] = a[i][j];
    }
  }
  for (int i = 1; i < n + 1; i++) {
    for (int j = 1; j < mx - 1; j++) {
      if (ans[i][j] == '*') {
        ans[i][j] = ' ';
      }
    }
  }
  trace(ans);
  for (int i = 0; i < n + 2; i++) {
    for (int j = 0; j < mx; j++) {
      cout << ans[i][j] << (j == mx - 1 ? "\n" : "");
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
