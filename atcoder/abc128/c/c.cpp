//=============================================================
// Name        : c
// Date        : Mon Jun 10 11:38:53 CST 2019
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
  vector<vector<int>> a(m);
  for (int i = 0; i < m; ++i) {
    int k;
    cin >> k;
    for (int j = 0; j < k; ++j) {
      int s;
      cin >> s;
      a[i].push_back(--s);
    }
  }
  vector<int> p(m);
  for (int i = 0; i < m; ++i) {
    cin >> p[i];
  }
  trace(n, m, a, p);
  int ans = 0;
  for (int state = 0; state < (1 << n); ++state) {
    vector<bool> light(n);
    int st = state;
    for (int i = 0; i < n; ++i) {
      light[i] = st & 1;
      st >>= 1;
    }
    // n, n-1, ... 1
    bool ok = 1;
    for (int i = 0; i < m; ++i) {
      int cnt = 0;
      for (int j = 0; j < sz(a[i]); ++j) {
        if (light[a[i][j]]) {
          cnt++;
        }
      }
      if (cnt % 2 != p[i]) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      ans++;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
