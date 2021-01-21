/* created   : 2021-01-21 22:12:35
 * accepted  : $ACCEPTED
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;

void solve() {
  int N; cin >> N;
  vector<vector<int>> g(N);
  Graphviz gv;
  for (int i = 0; i < N - 1; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    gv.gvAddEdge(u + 1, v + 1);
  }
  gv.gvDrawGraph();
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
