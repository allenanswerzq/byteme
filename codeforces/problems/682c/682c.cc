/* created   : 2020-05-01 22:17:33
 * accepted  : 2020-05-01 23:47:46
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e5 + 7;
vector<pair<int, int>> g[N];
int cnt[N];
bool use[N];
int a[N];
int ans;

void count(int u) {
  use[u] = true;
  cnt[u] = 1;
  for (auto [v, w] : g[u]) {
    if (!use[v]) {
      count(v);
      cnt[u] += cnt[v];
    }
  }
}

void dfs(int u, ll dist, ll mi) {
  trace("dfs", u, dist);
  use[u] = true;
  if (dist - mi > a[u]) {
    trace("remove", u, dist, a[u], mi);
    ans += cnt[u];
    return;
  }
  for (auto [v, w] : g[u]) {
    if (!use[v]) {
      dfs(v, dist + w, min(mi, dist));
    }
  }
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i + 1 < n; i++) {
    int p, c; cin >> p >> c;
    p--;
    g[p].push_back({i + 1, c});
    g[i + 1].push_back({p, c});
  }
  memset(use, 0, sizeof(use));
  count(0);
  trace(mt(cnt, n));
  memset(use, 0, sizeof(use));
  dfs(0, 0, (ll)1e18);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
