/* created   : 2020-07-21 08:15:31
 * accepted  : 2020-07-21 08:34:45
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

const int N = 6007;
vector<int> g[N];
int f[N][2];
int deg[N];
int a[N];
int n;

void dfs(int u, int p=-1) {
  // f[u][0] += max(f[v][0], f[v][1]);
  // f[u][1] += f[v][0];
  f[u][0] = 0;
  f[u][1] = a[u];
  for (auto v : g[u]) {
    if (v != p) {
      dfs(v, u);
      f[u][0] += max(f[v][0], f[v][1]);
      f[u][1] += f[v][0];
    }
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n - 1; i++) {
    int x, y; cin >> x >> y;
    // g[x].push_back(y);
    g[y].push_back(x);
    deg[x]++;
  }
  int root = -1;
  int cnt = 0;
  for (int i = 1; i <= n; i++) {
    if (deg[i] == 0) {
      root = i;
      cnt++;
    }
  }
  assert(cnt == 1);
  trace(root);
  dfs(root);
  cout << max(f[root][0], f[root][1]) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
