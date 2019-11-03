/* created   : 2019-11-03 12:05:09
 * accepted  : 2019-11-03 14:32:20
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

struct node {
  int x;
  int y;
  int h;
};

const int N = 520;
int depth[N][N];
bool use[N][N];
string a[N];
int n;
int m;
int k;

bool check(int x, int y) {
  bool ret = (0 <= x && x < n)
    && (0 <= y && y < m)
    && (a[x][y] == '.')
    && (!use[x][y]);
  return ret;
}

void bfs(int u, int v) {
  vector<int> dx = {0, 0, -1, 1};
  vector<int> dy = {-1, 1, 0, 0};
  deque<node> dq;
  dq.push_back({u, v, 0});
  while (!dq.empty()) {
    node t = dq.front();
    dq.pop_front();
    int x = t.x;
    int y = t.y;
    int h = t.h;
    if (use[x][y]) {
      continue;
    }
    depth[x][y] = h;
    use[x][y] = true;
    for (int i = 0; i < 4; i++) {
      int nx = x + dx[i];
      int ny = y + dy[i];
      if (check(nx, ny)) {
        dq.push_back({nx, ny, h + 1});
      }
    }
  }
}

void solve() {
  cin >> n >> m >> k;
  bool ok = 0;
  pair<int, int> root;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.' && !ok) {
        ok = true;
        root = {i, j};
      }
    }
  }
  bfs(root.x, root.y);
  vector<pair<int, pair<int, int>>> v;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] == '.') {
      v.push_back({depth[i][j], {i, j}});
      }
    }
  }
  trace(mt(depth, n, m));
  sort(v.rbegin(), v.rend());
  trace(root, v);
  for (int i = 0; i < k; i++) {
    a[v[i].y.x][v[i].y.y] = 'X';
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
