/* created   : 2019-08-18 09:21:07
 * accepted  : 2019-08-18 09:26:04
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
  int n, m, k;
  cin >> n >> m >> k;
  list<int> a;
  for (int i = 0; i < k; i++) {
    int x;
    cin >> x;
    a.push_back(x);
  }
  trace(a);
  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x;
      cin >> x;
      auto p = find(a.begin(), a.end(), x);
      ans += distance(a.begin(), p) + 1;
      int y = *p;
      a.erase(p);
      a.insert(a.begin(), y);
    }
  }
  trace(a);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
