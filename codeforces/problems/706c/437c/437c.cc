/* created   : 2020-04-05 17:38:28
 * accepted  : 2020-04-05 18:25:48
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> cost(n);
  for (int i = 0; i < n; i++) {
    cin >> cost[i];
  }
  vector<int> a;
  for (int i = 0; i < m; i++) {
    int u, v; cin >> u >> v;
    u--, v--;
    a.push_back(min(cost[u], cost[v]));
  }
  trace(a);
  cout << accumulate(all(a), 0ll) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
