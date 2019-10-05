//=============================================================
// Name        : 965b
// Date        : Sun Jun 30 11:08:53 CST 2019
// Accepted    : Sun Jun 30 12:10:45 CST 2019
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
  int n, k;
  cin >> n >> k;
  vector<string> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<vector<int>> cnt(n, vector<int>(n));
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j + k <= n; ++j) {
      bool ok = 1;
      for (int h = 0; h < k; ++h) {
        ok &= (a[i][j + h] == '.');
      }
      if (ok) {
        for (int h = 0; h < k; ++h) {
          cnt[i][j + h]++;
        }
      }
    }
  }
  for (int i = 0; i + k <= n; ++i) {
    for (int j = 0; j < n; ++j) {
      bool ok = 1;
      for (int h = 0; h < k; ++h) {
        ok &= (a[i + h][j] == '.');
      }
      if (ok) {
        for (int h = 0; h < k; ++h) {
          cnt[i + h][j]++;
        }
      }
    }
  }
  trace(cnt);
  int mx = 0;
  pair<int, int> ans = {0, 0};
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (mx < cnt[i][j]) {
        mx = cnt[i][j];
        ans = {i, j};
      }
    }
  }
  cout << ans.x + 1 << " " << ans.y + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
