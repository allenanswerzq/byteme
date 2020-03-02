/* created   : 2020-03-02 11:14:37
 * accepted  : 2020-03-02 11:30:41
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
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  set<int> st;
  vector<pair<int, int>> ans;
  int lo = -1;
  for (int i = 0; i < n; i++) {
    if (st.count(a[i])) {
      ans.push_back({lo + 1, i});
      st.clear();
      lo = i;
    }
    else {
      st.insert(a[i]);
    }
  }
  if (ans.empty()) {
    cout << -1 << '\n';
    return;
  }
  ans.back().y = n - 1;
  int m = ans.size();
  cout << m << '\n';
  for (int i = 0; i < m; i++) {
    cout << ans[i].x + 1 << " " << ans[i].y + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
