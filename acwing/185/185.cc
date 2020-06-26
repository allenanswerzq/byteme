/* created   : 2020-06-26 15:27:17
 * accepted  : 2020-06-26 18:36:20
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

int n;
int g[5][7], gg[5][5][7];
int cnt[11], ccnt[5][11];
bool st[5][7];
array<int, 3> path[5];

void move_to(int a, int b, int c) {
  swap(g[a][b], g[c][b]);
  while (true) {
    bool flag = false;
    for (int x = 0; x < 5; x++) {
      int z = 0;
      for (int y = 0; y < 7; y++) {
        if (g[x][y]) {
          g[x][z++] = g[x][y];
        }
      }
      while (z < 7) {
        g[x][z++] = 0;
      }
    }
    memset(st, false, sizeof st);
    for (int x = 0; x < 5; x++) {
      for (int y = 0; y < 7; y++) {
        if (g[x][y]) {
          if (1) {
            int l = x, r = x;
            while (l >= 0 && g[l][y] == g[x][y]) l--;
            while (r < 5 && g[r][y] == g[x][y]) r++;
            if (r - l - 1 >= 3) {
              flag = true;
              st[x][y] = true;
            }
          }
          if (!st[x][y]) {
            int l = y, r = y;
            while (l >= 0 && g[x][l] == g[x][y]) l--;
            while (r < 7 && g[x][r] == g[x][y]) r++;
            if (r - l - 1 >= 3) {
              flag = true;
              st[x][y] = true;
            }
          }
        }
      }
    }
    if (flag) {
      for (int x = 0; x < 5; x++) {
        for (int y = 0; y < 7; y++) {
          if (st[x][y]) {
            cnt[0]--;
            cnt[g[x][y]]--;
            g[x][y] = 0;
          }
        }
      }
    }
    else {
      break;
    }
  }
}

bool dfs(int u) {
  if (u == n) return !cnt[0];

  for (int i = 1; i <= 10; i++)
    if (cnt[i] == 1 || cnt[i] == 2) return false;

  memcpy(gg[u], g, sizeof g);
  memcpy(ccnt[u], cnt, sizeof cnt);
  for (int x = 0; x < 5; x++) {
    for (int y = 0; y < 7; y++) {
      if (g[x][y]) {
        int nx = x + 1;
        if (nx < 5) {
          path[u] = {x, y, 1};
          move_to(x, y, nx);
          if (dfs(u + 1)) return true;
          memcpy(g, gg[u], sizeof g);
          memcpy(cnt, ccnt[u], sizeof cnt);
        }
        nx = x - 1;
        if (nx >= 0 && !g[nx][y]) {
          path[u] = {x, y, -1};
          move_to(x, y, nx);
          if (dfs(u + 1)) return true;
          memcpy(g, gg[u], sizeof g);
          memcpy(cnt, ccnt[u], sizeof cnt);
        }
      }
    }
  }
  return false;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> n;
  for (int i = 0; i < 5; i++) {
    int j = 0, x;
    while (cin >> x && x) {
      cnt[0]++;
      cnt[x]++;
      g[i][j++] = x;
    }
  }
  if (dfs(0)) {
    for (int i = 0; i < n; i++) {
      cout << path[i][0] << " " << path[i][1] << " " << path[i][2] << "\n";
    }
  }
  else {
    cout << -1 << "\n";
  }
  return 0;
}
