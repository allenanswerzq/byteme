/* created   : 2020-07-30 06:36:05
 * accepted  : 2020-07-30 09:55:33
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define pii pair<int, int>

const int N = 2e5 + 7;
const int INF = 1e9;
vector<pii> g[N];
int f[N];
int d[N];
int n;

void bottom_up(int u, int pr = -1) {
  d[u] = g[u].size() == 1 ? INF : 0;
  for (auto [v, w] : g[u]) {
    if (v == pr) continue;
    bottom_up(v, u);
    d[u] += min(w, d[v]);
  }
}

void up_down(int u, int pr = -1) {
  for (auto [v, w] : g[u]) {
    if (v == pr) continue;
    if (g[v].size() == 1) {
      f[v] = min(w, f[u] - w);
    }
    else {
      f[v] = min(w, f[u] - min(w, d[v])) + d[v];
      up_down(v, u);
    }
  }
}

void solve() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    g[i].clear();
  }
  for (int i = 1; i < n; i++) {
    int x, y, z; cin >> x >> y >> z;
    g[x].push_back({y, z});
    g[y].push_back({x, z});
  }
  bottom_up(1);
  f[1] = d[1];
  up_down(1);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, f[i]);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  while (tc--) solve();
  return 0;
}
