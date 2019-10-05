//=============================================================
// Name        : 254a
// Date        : Sun Jun 30 15:05:43 CST 2019
// Accepted    : Sun Jun 30 15:20:26 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  vector<vector<int>> cnt(5200);
  for (int i = 0; i < 2 * n; ++i) {
    int x;
    cin >> x;
    cnt[x].push_back(i);
  }
  // trace(cnt);
  vector<pair<int, int>> ans;
  for (int i = 0; i < 5007; ++i) {
    vector<int> x = cnt[i];
    if (sz(x) % 2 == 1) {
      cout << -1 << "\n";
      return;
    }
    while (sz(x) > 0) {
      int a = x.back();
      x.pop_back();
      int b = x.back();
      x.pop_back();
      ans.emplace_back(a, b);
    }
  }
  for (int i = 0; i < sz(ans); ++i) {
    cout << ans[i].x + 1 << " " << ans[i].y + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
