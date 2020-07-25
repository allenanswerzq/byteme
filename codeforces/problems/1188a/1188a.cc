/* created   : 2020-04-18 22:39:58
 * accepted  : 2020-04-19 15:33:10
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> deg(n);
  for (int i = 0; i < n - 1; i++) {
    int u, v; cin >> u >> v;
    u--;
    v--;
    deg[u]++;
    deg[v]++;
  }
  for (int i = 0; i < n; i++) {
    if (deg[i] == 2) {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
