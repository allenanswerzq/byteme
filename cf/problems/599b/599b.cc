/* created   : 2020-03-02 20:27:27
 * accepted  : 2020-03-02 20:48:12
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
  int n, m; cin >> n >> m;
  unordered_map<int, vector<int>> cnt;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    cnt[x].push_back(i);
  }
  vector<int> ans(m);
  bool ok = false;
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    if (cnt[x].empty()) {
      cout << "Impossible" << '\n';
      return;
    }
    else if (cnt[x].size() > 1) {
      ok = true;
    }
    else {
      ans[i] = cnt[x].back();
    }
  }
  if (ok) {
    cout << "Ambiguity" << '\n';
    return;
  }
  trace(ans);
  cout << "Possible" << '\n';
  for (int i = 0; i < m; i++) {
    cout << ans[i] + 1 << (i == m - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
