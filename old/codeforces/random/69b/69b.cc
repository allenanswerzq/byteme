//=============================================================
// Name        : 69b
// Date        : Sun Jul  7 11:32:01 CST 2019
// Accepted    : Sun Jul  7 11:35:41 CST 2019
// Author      : landcold7
// Description : Action speaks louder more than words
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
  vector<int> time(n, 1200), val(n);
  for (int i = 0; i < m; ++i) {
    int l, r, t, c;
    cin >> l >> r >> t >> c;
    l--, r--;
    for (int j = l; j <= r; ++j) {
      if (t < time[j]) {
        time[j] = t;
        val[j] = c;
      }
    }
  }
  cout << accumulate(val.begin(), val.end(), 0ll) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
