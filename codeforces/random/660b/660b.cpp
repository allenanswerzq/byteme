//=============================================================
// Name        : 660b
// Date        : Sat Jun  1 20:40:28 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vi> a(n, vi(4));
  int s = 1;
  for (int i = 0; i < n; ++i) {
    a[i][0] = s++;
    a[i][3] = s++;
  }
  for (int i = 0; i < n; ++i) {
    a[i][1] = s++;
    a[i][2] = s++;
  }
  // trace(a);
  vector<int> ret;
  vi mp = {1, 0, 2, 3};
  for (int row = 0; row < n; ++row) {
    for (int i = 0; i < 4 && sz(ret) < m; ++i) {
      if (a[row][mp[i]] <= m) {
        ret.pb(a[row][mp[i]]);
      }
    }
    if (sz(ret) >= m) {
      break;
    }
  }
  for (int i = 0; i < m; ++i) {
    cout << ret[i] << (i == m - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
