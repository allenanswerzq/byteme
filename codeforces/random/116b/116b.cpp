//=============================================================
// Name        : 116b
// Date        : Sun Jun  9 15:04:15 CST 2019
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

const int maxn = 12;
char a[maxn][maxn];

void solve() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < maxn; ++i) {
    for (int j = 0; j < maxn; ++j) {
      a[i][j] = '#';
    }
  }
  for (int i = 1; i <= n; ++i) {
    scanf("%s", a[i] + 1);
  }
  for (int i = 0; i < maxn; ++i) {
    for (int j = 0; j < maxn; ++j) {
      cout << a[i][j];
    }
    cout << "\n";
  }
  vector<pair<int, int>> dir = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (a[i][j] == 'P') {
        for (auto d : dir) {
          if (a[i + d.x][j + d.y] == 'W') {
            a[i + d.x][j + d.y] = '.';
            ans++;
            break;
          }
        }
      }
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
