/* created   : 2020-02-07 10:44:11
 * accepted  : 2020-02-07 11:35:03
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

const int N = 2e5 + 30;
vector<int> g[N];
bool use[N];

void dfs(int u) {
  use[u] = true;
  for (auto v : g[u]) {
    if (!use[v]) {
      dfs(v);
    }
  }
}

void add_edge(int u, int v) {
  g[u].push_back(v);
  g[v].push_back(u);
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    string x; cin >> x;
    for (auto c : x) {
      // password i to alphabet char.
      add_edge(i, n + c - 'a');
    }
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    if (!g[n + i].empty() && !use[n + i]) {
      dfs(n + i);
      ans++;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
