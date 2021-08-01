/* created   : 2021-08-01 10:06:40
 * accepted  : 2021-08-01 15:17:19
 */
#include <bits/stdc++.h>
using namespace std;
// #define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N, M; cin >> N >> M;
  vector<int> g(N);
  for (int i = 0; i < N; i++) {
    g[i] |= (1 << i);
  }
  for (int i = 0; i < M; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    g[u] |= (1 << v);
    g[v] |= (1 << u);
  }
  const int INF = 1e9 + 7;
  vector<int> f(1 << N, INF);
  vector<ar> pre(1 << N);
  for (int s = 0; s < (1 << N); s++) {
    bool ok = true;
    for (int i = 0; i < N; i++) {
      if (((s >> i) & 1) && ((s & g[i]) != s)) {
        // If the state `s` does not have all nodes that i has
        ok = false;
        break;
      }
    }
    // trace(s, ok);
    if (ok) {
      // If state `s` is a full connected graph.
      f[s] = 0;
      pre[s][0] = -1;
    }
    for (int i = 0; i < N; i++) {
      // Transfer s --> s | g[i] using node `i`
      if (((s >> i) & 1) && f[s] + 1 < f[s | g[i]]) {
        pre[s | g[i]] = {i, s};
        f[s | g[i]] = f[s] + 1;
      }
    }
  }
  // trace(pre);
  // trace(mp);
  vector<int> ans;
  int s = (1 << N) - 1;
  while (pre[s][0] != -1) {
    ans.push_back(pre[s][0]);
    s = pre[s][1];
  }
  trace(ans, f[(1 << N) - 1]);
  assert(ans.size() == f[(1 << N) - 1]);
  cout << ans.size() << "\n";
  for (int i = 0; i < ans.size(); i++) {
    if (i > 0) {
      cout << " ";
    }
    cout << ans[i] + 1;
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
