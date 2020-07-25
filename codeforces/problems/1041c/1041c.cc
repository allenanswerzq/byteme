/* created   : 2019-10-13 23:32:50
 * accepted  : 2019-10-13 23:52:00
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
  int n, m, d; cin >> n >> m >> d;
  multiset<pair<ll, int>> st;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    st.insert({x, i});
  }
  trace(st);
  int g = 0;
  vector<int> ans(n);
  while (!st.empty()) {
    auto p = *st.begin();
    st.erase(st.begin());
    ans[p.y] = ++g;
    while (!st.empty()) {
      auto it = st.lower_bound({p.x + d + 1, -1});
      if (it == st.end()) {
        break;
      }
      ans[(*it).y] = g;
      p = *it;
      st.erase(it);
    }
  }
  cout << g << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
