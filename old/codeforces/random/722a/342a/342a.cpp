//=============================================================
// Name        : 342a
// Date        : Sun Jun 16 16:39:53 CST 2019
// Accepted    : Mon Jun 17 10:22:08 CST 2019
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
  vector<int> cnt(10);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  vector<vector<int>> ans;
  int b = min(min(cnt[4], cnt[2]), cnt[1]);
  for (int j = 0; j < b; ++j) {
    ans.push_back({1, 2, 4});
  }
  cnt[4] -= b;
  cnt[2] -= b;
  cnt[1] -= b;
  trace(cnt, ans);
  vector<int> x = {1, 2, 3};
  for (int i = 0; i < 3; ++i) {
    for (int j = i + 1; j < 3; ++j) {
      int u = x[i], v = x[j];
      if (u == 2 && v == 3) {
        continue;
      }
      int y = min(min(cnt[6], cnt[u]), cnt[v]);
      trace(u, v, 6, y);
      for (int h = 0; h < y; ++h) {
        ans.push_back({u, v, 6});
      }
      cnt[6] -= y;
      cnt[u] -= y;
      cnt[v] -= y;
    }
  }
  trace(cnt);
  for (int i = 0; i <= 7; ++i) {
    if (cnt[i] > 0) {
      cout << -1 << "\n";
      return;
    }
  }
  for (int i = 0; i < n / 3; ++i) {
    for (int j = 0; j < 3; ++j) {
      cout << ans[i][j] << (j == 2 ? "\n" : " ");
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
