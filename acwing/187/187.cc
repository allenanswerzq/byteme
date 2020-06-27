/* created   : 2020-06-27 15:42:42
 * accepted  : 2020-06-27 17:26:21
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 55;
const int INF = 1e9 + 7;
int a[N];
int inc[N], der[N];
int ans;
int n;

void dfs(int u, int ni, int nd) {
  if (u == n) {
    ans = min(ans, ni + nd);
    return;
  }
  if (ans <= ni + nd) return;
  {
    // -8 -7 -6 -6 -4 -3
    int p = upper_bound(inc, inc + ni, -a[u]) - inc;
    int tmp = inc[p];
    inc[p] = -a[u];
    dfs(u + 1, ni + (p == ni), nd);
    inc[p] = tmp;
  }
  {
    // 1 2 3 4 5 5
    int p = upper_bound(der, der + nd, a[u]) - der;
    int tmp = der[p];
    der[p] = a[u];
    dfs(u + 1, ni, nd + (p == nd));
    der[p] = tmp;
  }
}

void solve() {
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ans = INF;
  dfs(0, 0, 0);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  while (cin >> n && n) {
    solve();
  }
  return 0;
}
