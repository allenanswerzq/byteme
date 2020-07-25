/* created   : 2020-03-08 20:26:58
 * accepted  : 2020-03-09 10:28:48
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

void solve() {
  int n, k; cin >> n >> k;
  const int INF = 1e5 + 7;
  vector<int> start(n + 1, INF);
  vector<int> last(n + 1, 0);
  for (int i = 1; i <= k; i++) {
    int x; cin >> x;
    assert(1 <= x && x <= n);
    start[x] = min(start[x], i);
    last[x] = max(last[x], i);
  }
  // trace(start, last);
  ll ans = 0;
  for (int i = 1; i <= n; i++) {
    if (start[i] == INF) {
      ans++;
    }
    if (i > 1 && start[i] > last[i - 1]) {
      ans++;
    }
    if (i < n && start[i] > last[i + 1]) {
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
