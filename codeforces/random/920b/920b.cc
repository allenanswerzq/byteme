//=============================================================
// Name        : 920b
// Date        : Fri Jun 21 09:27:55 CST 2019
// Accepted    : Fri Jun 21 11:45:52 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> ans(n);
  int cur = 0;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    if (cur >= y) {
      ans[i] = 0;
    } else {
      ans[i] = max(cur + 1, x);
      cur = ans[i];
    }
  }
  for (int i = 0; i < n; ++i) {
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    solve();
  }
  return 0;
}
