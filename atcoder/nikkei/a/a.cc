/* created   : 2019-11-09 20:00:47
 * accepted  : 2019-11-09 20:03:38
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  unordered_set<int> st;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (st.count(n - i)) {
      ans++;
    }
    st.insert(i);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
