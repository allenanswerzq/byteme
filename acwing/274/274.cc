/* created   : 2020-07-09 19:40:03
 * accepted  : 2020-07-09 20:10:30
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void amin(int& a, int b) { a = min(a, b); }

const int L = 220;
const int N = 1e3 + 7;
int f[N][L][L];
int cost[L][L];
int pos[N];

void solve() {
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> cost[i][j];
    }
  }
  for (int i = 1; i <= m; i++) {
    cin >> pos[i];
  }
  memset(f, 0x3f, sizeof(f));
  pos[0] = 3;
  f[0][1][2] = 0;
  for (int i = 0; i < m; i++) {
    for (int x = 1; x <= n; x++) {
      for (int y = 1; y <= n; y++) {
        int z = pos[i];
        int u = pos[i + 1];
        if (x == y || y == z || x == z) continue;
        // move z to new place
        amin(f[i + 1][x][y], f[i][x][y] + cost[z][u]);
        // move x to new place
        amin(f[i + 1][z][y], f[i][x][y] + cost[x][u]);
        // move y to new place
        amin(f[i + 1][x][z], f[i][x][y] + cost[y][u]);
      }
    }
  }
  int ans = 1e9 + 7;
  for (int x = 1; x <= n; x++) {
    for (int y = 1; y <= n; y++) {
      int z = pos[m];
      if (x == y || y == z || x == z) continue;
      ans = min(ans, dbg(f[m][x][y]));
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
