//=============================================================
// Name        : 509b
// Date        : Thu Jun 13 10:33:26 CST 2019
// Accepted    : Thu Jun 13 11:29:18 CST 2019
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
  int n, m;
  cin >> n >> m;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].x;
    a[i].y = i;
  }
  sort(a.begin(), a.end());
  trace(a);
  int color = 1;
  vector<vector<int>> ans(n);
  for (int i = 0; i < n; ++i) {
    int tmp = 1;
    int cnt = (i == 0 ? a[0].x : a[0].x + 1);
    for (int j = 0; j < a[i].x; ++j) {
      if (j >= cnt) {
        tmp++;
      }
      ans[a[i].y].emplace_back(tmp);
    }
    color = max(color, tmp);
  }
  if (color > m) {
    cout << "NO" << "\n";
    return;
  }
  cout << "YES" << "\n";
  for (auto v : ans) {
    for (int i = 0; i < sz(v); ++i) {
      cout << v[i] << (i == sz(v) - 1 ? "\n" : " ");
    }
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
