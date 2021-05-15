/* created   : 2020-11-02 22:25:21
 * accepted  : 2020-11-04 08:17:18
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

vector<int> dx = {-1, 1, 0, 0};
vector<int> dy = {0, 0, -1, 1};
vector<char> ch = {'U', 'D', 'L', 'R'};
int ans = 0;
int vis[7][7];
string S;

void dfs(int u, int x, int y) {
  if (u > S.size()) {
    return;
  }
  if (x == 6 && y == 0) {
    if (u == S.size()) ans++;
    return;
  }
  vis[x][y] = 1;
  for (int k = 0; k < 4; k++) {
    int xx = x + dx[k];
    int yy = y + dy[k];
    if (!(0 <= xx && xx < 7)) continue;
    if (!(0 <= yy && yy < 7)) continue;
    if (vis[xx][yy]) continue;
    if (!(S[u] == '?' || S[u] == ops[k])) continue;
    dfs(u + 1, xx, yy);
  }
  vis[x][y] = 0;
}

void solve() {
  cin >> S;
  dfs(0, 0, 0);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
