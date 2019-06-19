//=============================================================
// Name        : 352b
// Date        : Sat Jun 15 15:27:43 CST 2019
// Accepted    : Sat Jun 15 15:51:06 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  const int maxn = 1e5 + 7;
  vector<vector<int>> pos(maxn);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    pos[a[i]].push_back(i);
  }
  // trace(pos);
  vector<pair<int, int>> ans;
  for (int i = 0; i < maxn; ++i) {
    int np = (int) pos[i].size();
    if (np == 1) {
      ans.emplace_back(i, 0);
    } else if (np > 1) {
      sort(pos[i].begin(), pos[i].end());
      int d = pos[i][1] - pos[i][0];
      bool ok = 1;
      for (int j = 2; j < np; ++j) {
        if (pos[i][j] - pos[i][j - 1] != d) {
          ok = 0;
          break;
        }
      }
      if (ok) {
        ans.emplace_back(i, d);
      }
    }
  }
  int na = (int) ans.size();
  cout << na << "\n";
  for (int i = 0; i < na; ++i) {
    cout << ans[i].first << " " << ans[i].second << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
