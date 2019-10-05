/*
 * created   : 2019-07-30 22:57:25
 * accepted  : 2019-07-30 23:40:03
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
  vector<vector<int>> a(m, vector<int>(3));
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }
  trace(a);
  vector<int> ans(n + 1, -1);
  for (int i = 0; i < 3; i++) {
    ans[a[0][i]] = i;
  }
  for (int i = 1; i < m; i++) {
    int z = -1;
    for (int j = 0; j < 3; j++) {
      if (ans[a[i][j]] != -1) {
        z = j;
      }
    }
    if (z == -1) {
      for (int j = 0; j < 3; j++) {
        ans[a[i][j]] = j;
      }
    }
    else {
      vector<int> t = {0, 1, 2};
      t.erase(find(t.begin(), t.end(), ans[a[i][z]]));
      int k = 0;
      for (int j = 0; j < 3; j++) {
        if (ans[a[i][j]] == -1) {
          ans[a[i][j]] = t[k++];
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] + 1 << (i == n ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
