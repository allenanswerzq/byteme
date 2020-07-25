/* created   : 2019-11-10 22:35:45
 * accepted  : 2019-11-10 23:07:07
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int N = 52;
vector<string> a;
bool use[N][N];
int cnt;
int n;
int m;
int k;

void dfs(int x, int y, char draw = '@') {
  vector<int> dx = {0, 0, -1, 1};
  vector<int> dy = {1, -1, 0, 0};
  cnt++;
  use[x][y] = true;
  if (draw != '@') {
    a[x][y] = draw;
  }
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (0 <= nx && nx < n && 0 <= ny && ny < m
        && a[nx][ny] == '.' && !use[nx][ny]) {
      dfs(nx, ny, draw);
    }
  }
}

bool is_ocean(int x, int y) {
  return (x == 0 || x == n - 1 || y == 0 || y == m - 1);
}

void solve() {
  cin >> n >> m >> k;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  memset(use, 0, sizeof(use));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.' && is_ocean(i, j) && !use[i][j]) {
        dfs(i, j, '#');
      }
    }
  }
  trace(a);
  memset(use, 0, sizeof(use));
  vector<pair<int, pair<int, int>>> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.' && !use[i][j]) {
        cnt = 0;
        dfs(i, j);
        v.push_back({cnt, {i, j}});
      }
    }
  }
  sort(v.begin(), v.end());
  trace(a, v);
  int ans = 0;
  memset(use, 0, sizeof(use));
  for (int i = 0; i < (int) v.size() - k; i++) {
    ans += v[i].x;
    dfs(v[i].y.x, v[i].y.y, '*');
  }
  cout << ans << '\n';
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '#') {
        a[i][j] = '.';
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << a[i] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
