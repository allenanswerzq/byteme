/* created   : 2020-03-15 09:05:24
 * accepted  : 2020-03-15 10:11:27
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, m; cin >> n >> m;
  vector<int> a;
  for (int i = 0; i < n; i++) {
    int x = 0;
    for (int j = 0; j < m; j++) {
      int y; cin >> y;
      x = x * 2 + y;
    }
    a.push_back(x);
  }
  trace(a);
  for (int state = 0; state < (1 << m); state++) {
    int p = -1;
    for (int j = 0; j < n; j++) {
      if (a[j] == state) {
        p = j;
        break;
      }
    }
    if (p == -1) continue;
    if (state == 0) {
      cout << "YES" << '\n';
      return;
    }
    for (int j = 0; j < n; j++) {
      if (j != p && (a[j] & state) == 0) {
        trace(state, a[j]);
        cout << "YES" << '\n';
        return;
      }
    }
  }
  cout << "NO" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
