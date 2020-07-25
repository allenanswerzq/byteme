/* created   : 2020-03-18 22:10:57
 * accepted  : 2020-03-19 00:11:22
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

string a[8];
bool can[8][8][8][8];
int dx[] = {-2, 2, -2, 2};
int dy[] = {-2, -2, 2, 2};

void dfs(int x1, int y1, int x2, int y2) {
  can[x1][y1][x2][y2] = true;
  // Both knights move one step at one time.
  for (int i = 0; i < 4; i++) {
    int nx1 = x1 + dx[i];
    int ny1 = y1 + dy[i];
    if (!(0 <= nx1 && nx1 < 8 && 0 <= ny1 && ny1 < 8)) continue;
    for (int j = 0; j < 4; j++) {
      int nx2 = x2 + dx[j];
      int ny2 = y2 + dy[j];
      if (!(0 <= nx2 && nx2 < 8 && 0 <= ny2 && ny2 < 8)) continue;
      if (!can[nx1][ny1][nx2][ny2]) {
        dfs(nx1, ny1, nx2, ny2);
      }
    }
  }
}

void solve() {
  int x1 = -1, y1, x2, y2;
  for (int i = 0; i < 8; i++) {
    cin >> a[i];
    for (int j = 0; j < 8; j++) {
      if (a[i][j] == 'K') {
        if (x1 == -1) {
          x1 = i;
          y1 = j;
        }
        else {
          x2 = i;
          y2 = j;
        }
      }
    }
  }
  memset(can, 0, sizeof(can));
  // can[x1][y1][x2][y2] denotes whether the second
  // knight can be in the (x2, y2) position, when the first
  // knight at the (x1, y1) position.
  dfs(x1, y1, x2, y2);
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (a[i][j] != '#' && can[i][j][i][j]) {
        cout << "YES" << '\n';
        return;
      }
    }
  }
  cout << "NO" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
