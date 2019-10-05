/* created   : 2019-09-07 21:46:16
 * accepted  : 2019-09-07 23:01:24
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
  vector<vector<int>> a(n + 1);
  for (int i = 2; i <= n; i++) {
    for (int j = 2; j * j <= i; j++) {
      if (i % j == 0) {
        int x = i / j;
        if (x % j) {
          a[i].push_back(j);
          a[i].push_back(i / j);
        }
      }
    }
  }
  // trace(a);
  vector<int> ans;
  for (int i = 2; i <= n; i++) {
    if ((int) a[i].size() <= 0) {
      ans.push_back(i);
    }
  }
  trace(ans);
  int sz = ans.size();
  cout << sz << '\n';
  for (int i = 0; i < sz; i++) {
    cout << ans[i] << (i == sz - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
