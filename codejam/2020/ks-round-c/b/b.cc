/* created   : 2020-05-17 19:51:27
 * accepted  : 2020-05-17 20:33:14
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  set<int> g[26];
  int n, m; cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> use(26);
  if (n == 1) {
    for (int i = 0; i < m; i++) {
      use[a[0][i] - 'A'] = 1;
    }
    string ans;
    for (int i = 0; i < 26; i++) {
      if (use[i]) {
        ans += (char)('A' + i);
      }
    }
    cout << ans << "\n";
    return;
  }
  for (int i = 0; i + 1 < n; i++) {
    for (int j = 0; j < m; j++) {
      int u = a[i + 1][j] - 'A';
      int v = a[i][j] - 'A';
      // trace(u, v);
      if (u != v && g[v].count(u)) {
        cout << -1 << "\n";
        return;
      }
      use[u] = 1;
      use[v] = 1;
      if (u != v) {
        g[u].insert(v);
      }
    }
  }
  vector<int> deg(26);
  for (int i = 0; i < 26; i++) {
    for (auto x : g[i]) {
      // char u = (char)('A' + i);
      // char v = (char)('A' + x);
      // trace(i, x, u, v);
      deg[x]++;
    }
  }
  // trace(mt(g, N));
  string ans;
  while (1) {
    bool ok = false;
    for (int u = 0; u < 26; u++) {
      if (use[u] == 1 && deg[u] == 0) {
        use[u] = 2;
        ans += (char) (u + 'A');
        for (auto v : g[u]) {
          // trace("before", u, v, deg[u], deg[v]);
          deg[v]--;
          // trace(u, v, deg[u], deg[v]);
        }
        ok = true;
        break;
      }
    }
    // trace(ans, use, deg, ok);
    if (!ok) {
      break;
    }
  }
  trace(deg, ans);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
