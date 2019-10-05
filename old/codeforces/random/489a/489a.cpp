//=============================================================
// Name        : 489a
// Date        : Tue Jun 11 10:05:36 CST 2019
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<pair<int, int>> ans;
  for (int i = 0; i < n; ++i) {
    int j = min_element(a.begin() + i, a.end()) - a.begin();
    if (j != i) {
      ans.emplace_back(i, j);
      swap(a[i], a[j]);
    }
  }
  cout << sz(ans) << "\n";
  for (int i = 0; i < sz(ans); ++i) {
    cout << ans[i].x << " " << ans[i].y << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
