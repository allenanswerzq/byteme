/* created   : 2020-02-20 23:36:00
 * accepted  : 2020-02-20 23:59:08
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

#define pii pair<int, int>

bool comp(const pii& a, const pii& b) {
  if (a.x != b.x) {
    return a.x < b.x;
  }
  else {
    return a.y > b.y;
  }
}

void solve() {
  int n; cin >> n;
  vector<pii> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  sort(all(a), comp);
  trace(a);
  ll ans = 0;
  set<int> st;
  for (int i = 0; i < n; i++) {
    if (st.upper_bound(a[i].y) != st.end()) {
      trace(i, a[i]);
      ans++;
    }
    st.insert(a[i].y);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
