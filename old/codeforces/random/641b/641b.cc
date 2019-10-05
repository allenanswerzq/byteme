/*
 * created   : 2019-08-04 14:43:47
 * accepted  : 2019-08-04 15:56:29
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int N = 120;
int a[N][N];
pair<int, int> ha[N][N];

void solve() {
  int n, m, q;
  cin >> n >> m >> q;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      ha[i][j] = make_pair(i, j);
    }
  }
  for (int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if (t == 1) {
      int x;
      cin >> x;
      x--;
      pair<int, int> v = ha[x][0];
      for (int j = 0; j < m - 1; j++) {
        ha[x][j] = ha[x][j + 1];
      }
      ha[x][m - 1] = v;
    }
    else if (t == 2) {
      int x;
      cin >> x;
      x--;
      pair<int, int> v = ha[0][x];
      for (int j = 0; j < n - 1; j++) {
        ha[j][x] = ha[j + 1][x];
      }
      ha[n - 1][x] = v;
    }
    else {
      int r, c, x;
      cin >> r >> c >> x;
      r--, c--;
      a[ha[r][c].x][ha[r][c].y] = x;
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cout << a[i][j] << (j == m - 1 ? "\n" : " ");
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
