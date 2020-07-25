/* created   : 2019-10-15 17:56:50
 * accepted  : 2019-10-15 17:59:50
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
  int n, m; cin >> n >> m;
  vector<vector<int>> a(n + m);
  vector<vector<int>> b(n + m);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x; cin >> x;
      a[i + j].push_back(x);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int x; cin >> x;
      b[i + j].push_back(x);
    }
  }
  for (int i = 0; i < n + m ; i++) {
    sort(a[i].begin(), a[i].end());
    sort(b[i].begin(), b[i].end());
    if (a[i] != b[i]) {
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
