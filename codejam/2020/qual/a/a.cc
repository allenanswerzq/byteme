/* created   : 2020-04-04 08:24:19
 * accepted  : 2020-04-04 08:34:02
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<vector<int>> a(n, vector<int>(n));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  int row_cnt = 0;
  for (int i = 0; i < n; i++) {
    set<int> row;
    bool ok = false;
    for (int j = 0; j < n; j++) {
      if (i == j) {
        ans += a[i][j];
      }
      if (row.count(a[i][j])) {
        ok = true;
      }
      row.insert(a[i][j]);
    }
    row_cnt += ok;
  }
  int col_cnt = 0;
  for (int j = 0; j < n; j++) {
    set<int> col;
    bool ok = false;
    for (int i = 0; i < n; i++) {
      if (col.count(a[i][j])) {
        ok = true;
      }
      col.insert(a[i][j]);
    }
    col_cnt += ok;
  }
  cout << ans << ' ' << row_cnt << ' ' << col_cnt << '\n';
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
