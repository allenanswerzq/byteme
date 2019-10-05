//=============================================================
// Name        : 635a
// Date        : Tue Jun  4 10:10:21 CST 2019
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
typedef vector<int> vi;

void solve() {
  int r, c, n, d;
  cin >> r >> c >> n >> d;
  vector<vector<char>> a(r, vector<char>(c, '*'));
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    a[x][y] = '#';
  }
  trace(a);
  int ret = 0;
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      for (int k = i; k < r; ++k) {
        for (int h = j; h < c; ++h) {
          int cnt = 0;
          for (int x = i; x <= k; ++x) {
            for (int y = j; y <= h; ++y) {
              if (a[x][y] == '#') {
                cnt++;
              }
            }
          }
          if (cnt >= d) {
            ret++;
          }
        }
      }
    }
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
