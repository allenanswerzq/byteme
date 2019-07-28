/*
 * created   : 2019-07-28 14:45:50
 * accepted  : 2019-07-28 15:13:00
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

void solve(int tc) {
  int n, g, m;
  cin >> n >> g >> m;
  vector<vector<pair<int, int>>> a(n);
  for (int i = 0; i < g; ++i) {
    int x;
    char y;
    cin >> x >> y;
    x--;
    a[x].emplace_back(i, 0);
    trace(x, y, m);
    if (y == 'C') {
      for (int j = 1; j <= m; j++) {
        int t = (x + j) % n;
        assert(0 <= t && t < n);
        a[t].emplace_back(i, j);
      }
    }
    else {
      for (int j = 1; j <= m; j++) {
        int t = ((x - j + n) % n + n) % n;
        assert(0 <= t && t < n);
        a[t].emplace_back(i, j);
      }
    }
  }
  for (int i = 0; i < n; ++i) {
    typedef pair<int, int> pii;
    sort(a[i].begin(), a[i].end(), [](pii& x, pii& y){
      return x.y > y.y;
    });
  }
  trace(a);
  vector<int> ans(g);
  for (int i = 0; i < n; i++) {
    if (!a[i].empty()) {
      ans[a[i][0].x]++;
      for (int j = 1; j < (int) a[i].size(); j++) {
        if (a[i][j].y == a[i][0].y) {
          ans[a[i][j].x]++;
        }
      }
    }
  }
  cout << "Case #" << tc << ": ";
  for (int i = 0; i < g; ++i) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i];
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc;
  cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve(i);
  }
  return 0;
}
