/* created   : 2019-09-08 12:01:49
 * accepted  : 2019-09-08 12:30:07
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

const int N = 55;
int n, m;
vector<string> a;
int seen[N * N];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

void dfs(int u, char ch, int pr=-1) {
  int x = u / m;
  int y = u % m;
  trace("path", x, y, n, m);
  if (seen[u]) {
    trace("end", x, y, u, seen[u]);
    cout << "Yes\n";
    exit(0);
  }
  seen[u] = 1;
  for (int i = 0; i < 4; i++) {
    int nx = x + dx[i];
    int ny = y + dy[i];
    if (!(0 <= nx && nx < n && 0 <= ny && ny < m)) {
      continue;
    }
    if (nx * m + ny != pr && a[nx][ny] == ch) {
      dfs(nx * m + ny, ch, u);
    }
  }
}

void solve() {
  cin >> n >> m;
  a.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  trace(a);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      memset(seen, 0, sizeof(seen));
      trace("start", i, j);
      dfs(i * m + j, a[i][j]);
    }
  }
  cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
