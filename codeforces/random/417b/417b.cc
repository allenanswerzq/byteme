/* created   : 2019-08-28 23:11:54
 * accepted  : 2019-08-28 23:26:09
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
  int n; cin >> n;
  set<pair<int, int>> st;
  for (int i = 0; i < n; i++) {
    int x, k; cin >> x >> k;
    if (x > 0) {
      trace(x, k);
      if (!st.count({x - 1, k})) {
        cout << "NO\n";
        return;
      }
    }
    st.insert({x, k});
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
