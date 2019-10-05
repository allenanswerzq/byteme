//=============================================================
// Name        : 102a
// Date        : Sat Jul  6 11:15:22 CST 2019
// Accepted    : Sat Jul  6 12:04:17 CST 2019
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
  int n, m;
  cin >> n >> m;
  if (n < 3 || m < 3) {
    cout << -1 << "\n";
    return;
  }
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  set<pair<int, int>> st;
  for (int i = 0; i < m; ++i) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (x > y) {
      swap(x, y);
    }
    st.insert({x, y});
  }
  trace(st);
  int ans = (1 << 30);
  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      for (int k = k + 1; k < n; ++k) {
        if (st.count({i, j}) && st.count({j, k}) && st.count({i, k})) {
          ans = min(ans, a[i] + a[j] + a[k]);
        }
      }
    }
  }
  cout << (ans == (1 << 30) ? -1 : ans) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
