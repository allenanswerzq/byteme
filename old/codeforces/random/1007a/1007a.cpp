//=============================================================
// Name        : 1007a
// Date        : Thu Jun  6 10:46:31 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
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
  multiset<int> st;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    st.insert(a[i]);
  }
  sort(a.begin(), a.end());
  int ans = 0;
  for (int i = 0; i < n; ++i) {
    auto it = st.upper_bound(a[i]);
    if (it != st.end()) {
      ans++;
      st.erase(it);
    } else {
      break;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
