/* created   : 2020-03-25 21:59:21
 * accepted  : 2020-03-25 23:16:11
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
#define xuyixuyi()
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, t; cin >> n >> t;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<pair<string, string>> st;
  for (int i = 0; i < t; i++) {
    string x, y; cin >> x >> y;
    st.insert({x, y});
    st.insert({y, x});
  }
  int mx = 0;
  vector<string> ans;
  for (int i = (1 << n) - 1; i >= 0; i--) {
    vector<string> g;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        g.push_back(a[j]);
      }
    }
    trace(i, g);
    int m = g.size();
    bool ok = true;
    for (int j = 0; j < m; j++) {
      for (int k = j + 1; k < m; k++) {
        if (st.count({g[j], g[k]})) {
          ok = false;
          break;
        }
      }
    }
    if (ok && m > mx) {
      mx = m;
      ans = g;
    }
  }
  sort(all(ans));
  cout << ans.size() << '\n';
  for (int j = 0; j < ans.size(); j++) {
    cout << ans[j] << '\n';
  }
  return;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
