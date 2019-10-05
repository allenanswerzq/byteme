/* created   : 2019-08-10 09:34:26
 * accepted  : 2019-08-10 10:19:16
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
  int n, m;
  cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int mx = -1;
  int ix = m;
  int my = -1;
  int iy = n;
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'X') {
        mx = max(mx, j);
        ix = min(ix, j);
        my = max(my, i);
        iy = min(iy, i);
        cnt++;
      }
    }
  }
  int ans = (mx - ix + 1) * (my - iy + 1);
  cout << (ans == cnt ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
