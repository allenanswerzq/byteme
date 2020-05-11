/* created   : 2020-05-11 22:12:56
 * accepted  : 2020-05-11 22:50:59
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e5 + 7;
vector<int> g[N];
vector<int> f[N];
vector<int> good[N];
int use[N];
int use_cnt = 0;
int n, m, k, s;

void bfs(int root) {
  deque<int> dq;
  const int INF = 2e9 + 7;
  vector<ll> dist(n, INF);
  for (auto v : good[root]) {
    dq.push_back(v);
    dist[v] = 0;
    use[v] = use_cnt;
  }
  while (!dq.empty()) {
    int u = dq.front();
    dq.pop_front();
    for (auto v : g[u]) {
      if (use[v] < use_cnt && dist[v] > dist[u] + 1) {
        dist[v] = dist[u] + 1;
        dq.push_back(v);
        use[v] = use_cnt;
      }
    }
  }
  trace(root, good[root], dist);
  for (int i = 0; i < n; i++) {
    f[i].push_back(dist[i]);
  }
}

void solve() {
  cin >> n >> m >> k >> s;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    good[x].push_back(i);
  }
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  for (int i = 1; i <= k; i++) {
    if (!good[i].empty()) {
      use_cnt++;
      bfs(i);
    }
  }
  for (int i = 0; i < n; i++) {
    sort(all(f[i]));
    if (i > 0) {
      cout << " ";
    }
    cout << accumulate(f[i].begin(), f[i].begin() + s, 0ll);
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
