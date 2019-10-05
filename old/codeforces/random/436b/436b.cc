/* created   : 2019-08-14 20:54:25
 * accepted  : 2019-08-14 21:06:24
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
  int n, m, k;
  cin >> n >> m >> k;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> ans(m);
  for (int i = 1; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == 'R') {
        if (i + j < m) {
          ans[i + j]++;
        }
      }
      else if (a[i][j] == 'L') {
        if (j - i >= 0) {
          ans[j - i]++;
        }
      }
      else if (a[i][j] == 'U') {
        if (i % 2 == 0) {
          ans[j]++;
        }
      }
    }
  }
  for (int i = 0; i < m; i++) {
    cout << ans[i] << (i == m - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
