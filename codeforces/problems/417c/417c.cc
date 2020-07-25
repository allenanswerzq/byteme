/* created   : 2020-03-09 22:23:43
 * accepted  : 2020-03-09 22:49:42
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

const int N = 1e3 + 7;
bool use[N][N];
vector<int> g[N];

void solve() {
  int n, k; cin >> n >> k;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int cnt = 0;
    for (int j = 1; j <= n; j++) {
      if (j == i) continue;
      if (!use[i][j]) {
        use[i][j] = use[j][i] = true;
        g[i].push_back(j);
        ans++;
        if (++cnt == k) {
          break;
        }
      }
    }
    trace(i, cnt, k);
    if (cnt < k) {
      cout << -1 << '\n';
      return;
    }
  }
  cout << ans << '\n';
  for (int i = 1; i <= n; i++) {
    for (auto v : g[i]) {
      cout << i << ' ' << v << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
