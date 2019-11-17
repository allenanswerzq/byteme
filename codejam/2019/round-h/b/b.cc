/* created   : 2019-11-17 13:25:11
 * accepted  : 2019-11-17 14:25:31
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

int rec(vector<string> a, bool dir, int cnt) {
  // trace(a, dir);
  int n = a.size();
  bool ok = true;
  pair<int, int> p;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (a[i][j] == '.') {
        ok = false;
        p = {i, j};
        break;
      }
    }
    if (!ok) {
      break;
    }
  }
  if (ok || cnt > 15) {
    return 0;
  }
  int x = p.x;
  int y = p.y;
  if (dir) {
    // trace("dir true");
    for (int i = x, j = y; i >= 0 && j >= 0; i--, j--) {
      a[i][j] = a[i][j] == '.' ? '#' : '.';
    }
    for (int i = x + 1, j = y + 1; i < n && j < n; i++, j++) {
      a[i][j] = a[i][j] == '.' ? '#' : '.';
    }
  }
  else {
    // trace("dir false");
    for (int i = x, j = y; i >= 0 && j < n; i--, j++) {
      a[i][j] = a[i][j] == '.' ? '#' : '.';
    }
    for (int i = x + 1, j = y - 1; i < n && j >= 0; i++, j--) {
      a[i][j] = a[i][j] == '.' ? '#' : '.';
    }
  }
  int t = rec(a, true, cnt + 1);
  int f = rec(a, false, cnt + 1);
  return min(t, f) + 1;
}

void solve() {
  int n; cin >> n;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = min(rec(a, true, 0), rec(a, false, 0));
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
