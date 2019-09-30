/* created   : 2019-09-13 18:02:55
 * accepted  : 2019-09-13 20:53:39
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

const int N = 520;
int hor[N][N];
int ver[N][N];

int get(int x1, int y1, int x2, int y2) {
  int a = hor[x2][y2] - hor[x1 - 1][y2] - hor[x2][y1] + hor[x1 - 1][y1];
  int b = ver[x2][y2] - ver[x1][y2] - ver[x2][y1 - 1] + ver[x1][y1 - 1];
  return a + b;
}

void solve() {
  int n, m; cin >> n >> m;
  vector<string> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  for (int i = 0; i < n; i++) {
    for (int j = 1; j < m; j++) {
      hor[i + 1][j + 1] = hor[i][j + 1] + hor[i + 1][j] - hor[i][j];
      if (v[i][j - 1] == '.' && v[i][j] == '.') {
        hor[i + 1][j + 1] += 1;
      }
    }
  }
  for (int j = 0; j < m; j++) {
    for (int i = 1; i < n; i++) {
      ver[i + 1][j + 1] = ver[i][j + 1] + ver[i + 1][j] - ver[i][j];
      if (v[i][j] == '.' && v[i - 1][j] == '.') {
        ver[i + 1][j + 1] += 1;
      }
    }
  }
  trace(make_tuple(hor, n + 1, m + 1));
  trace(make_tuple(ver, n + 1, m + 1));
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int r1, c1, r2, c2;
    cin >> r1 >> c1 >> r2 >> c2;
    cout << get(r1, c1, r2, c2) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
