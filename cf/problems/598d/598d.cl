/* created   : 2020-04-28 18:16:30
 * accepted  : 2020-04-28 20:17:16
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1230;
const int M = 1e5 + 7;
int f[M];
int use[N][N];
string a[N];
int n, m, q, ans; 

void dfs(int x, int y, int cnt) {
  if (!(0 <= x && x < n && 0 <= y && y < m)) return;
  if (a[x][y] == '*') {
    ans++;
    return;
  }
  if (use[x][y] != -1) return;
  use[x][y] = cnt;
  dfs(x + 1, y, cnt);
  dfs(x - 1, y, cnt);
  dfs(x, y - 1, cnt);
  dfs(x, y + 1, cnt);
}

void solve() {
  cin >> n >> m >> q; 
  for (int i = 0; i < n; i++) {
    cin >> a[i]; 
  }
  memset(use, 0xff, sizeof(use));
  for (int i = 0; i < q; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    if (use[x][y] == -1) {
      ans = 0;
      dfs(x, y, i);
      f[use[x][y]] = ans;
    }
    else {
      ans = f[use[x][y]];
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve(); return 0;
}
