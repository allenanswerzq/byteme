/* created   : 2020-11-13 11:08:14
 * accepted  : 2020-11-13 11:31:26
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 520;
int f[N][N];

int dfs(int x, int y) {
  if (x < y) swap(x, y);
  // trace(x, y, f[x][y]);
  if (f[x][y] != -1) return f[x][y];
  if (y == 1) {
    return x - 1;
  }
  if (x == y) {
    return 0;
  }
  int ans = 1e9 + 7;
  for (int i = 1; i < x; i++) {
    ans = min(ans, dfs(y, i) + dfs(y, x - i) + 1);
  }
  for (int i = 1; i < y; i++) {
    ans = min(ans, dfs(i, x) + dfs(y - i, x) + 1);
  }
  return f[x][y] = ans;
}

void solve() {
  int x, y; cin >> x >> y;
  memset(f, -1, sizeof(f));
  cout << dfs(x, y) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
