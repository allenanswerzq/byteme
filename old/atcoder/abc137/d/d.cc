/* created   : 2019-08-13 20:19:33
 * accepted  : 2019-08-14 09:40:17
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;
  vector<vector<int>> a(m);
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (x <= m) {
      a[m - x].push_back(y);
    }
  }
  priority_queue<int> q;
  ll ans = 0;
  for (int i = m - 1; i >= 0; i--) {
    for (auto t : a[i]) {
      q.push(t);
    }
    if (!q.empty()) {
      ans += q.top();
      q.pop();
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
