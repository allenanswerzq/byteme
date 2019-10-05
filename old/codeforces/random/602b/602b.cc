/*
 * creat   : 2019-07-18 16:10:03
 * accept  : 2019-07-18 19:16:52
 * author  : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  multiset<int> st;
  int ans = 0;
  int lo = 0;
  for (int i = 0; i < n; ++i) {
    st.insert(a[i]);
    while (*st.rbegin() - *st.begin() > 1) {
      st.erase(st.find(a[lo++]));
    }
    ans = max(ans, (int) st.size());
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
