/* created   : 2020-03-09 17:52:48
 * accepted  : 2020-03-09 18:06:55
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
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> a[i][j];
    }
  }
  auto check = [&](vector<vector<int>>& b) {
    for (int i = 0; i < n; i++) {
      vector<pair<int, int>> t(m);
      for (int j = 0; j < m; j++) {
        t[j].x = b[i][j];
        t[j].y = j;
      }
      sort(all(t));
      int cnt = 0;
      for (int j = 0; j < m; j++) {
        if (t[j].y != j) {
          cnt++;
        }
      }
      if (!(cnt == 0 || cnt == 2)) {
        return false;
      }
    }
    return true;
  };
  if (check(a)) {
    cout << "YES" << '\n';
    return;
  }
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      vector<vector<int>> b = a;
      for (int k = 0; k < n; k++) {
        swap(b[k][i], b[k][j]);
      }
      // trace(i, j, b);
      if (check(b)) {
        cout << "YES" << '\n';
        return;
      }
    }
  }
  cout << "NO" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
