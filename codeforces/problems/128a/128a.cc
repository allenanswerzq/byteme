/* created   : 2019-11-01 23:35:04
 * accepted  : 2019-11-02 11:42:52
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
  int step;
};

vector<string> a(8);
bool use[10][10][1024];

void solve() {
  for (int i = 0; i < 8; i++) {
    cin >> a[i];
  }
  trace(a);
  deque<node> dq;
  dq.push_back(node{7, 0, 0});
  while (!dq.empty()) {
    auto t = dq.front();
    dq.pop_front();
    int x = t.x;
    int y = t.y;
    int step = t.step;
    if (x == 0 && y == 7) {
      cout << "WIN" << '\n';
      return;
    }
    use[x][y][step] = true;
    for (int dx = -1; dx <= 1; dx++) {
      for (int dy = -1; dy <= 1; dy++) {
        int nx = x + dx;
        int ny = y + dy;
        if (!(0 <= nx && nx < 8 && 0 <= ny && ny < 8)) {
          continue;
        }
        if (use[nx][ny][step + 1]) {
          continue;
        }
        // If the cell before we jump to is already `S`
        if (nx - step >= 0 && a[nx - step][ny] == 'S') {
          continue;
        }
        // If the cell after we jump to will become `S`
        if (nx - step - 1 >= 0 && a[nx - step - 1][ny] == 'S') {
          continue;
        }
        dq.push_back(node{nx, ny, step + 1});
      }
    }
  }
  cout << "LOSE" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
