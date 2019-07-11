//=============================================================
// Name        : 586b
// Date        : Sun Jun 23 15:37:16 CST 2019
// Accepted    : Sun Jun 23 15:58:53 CST 2019
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
  vector<vector<int>> a(2, vector<int>(n - 1));
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n - 1; ++j) {
      cin >> a[i][j];
    }
  }
  vector<int> b(n);
  for (int i = 0; i < n; ++i) {
    cin >> b[i];
  }
  trace(a);
  auto get = [&](int x) {
    int ans = 0;
    for (int i = n - 1; i >= 0; --i) {
      if (i > x) {
        ans += a[1][i - 1];
      } else {
        ans += i > 0 ? a[0][i - 1] : 0;
      }
      if (i == x) {
        ans += b[i];
      }
    }
    return ans;
  };
  int ans = (1 << 30);
  for (int i = n - 1; i >= 0; --i) {
    for (int j = i - 1; j >= 0; --j) {
      ans = min(ans, get(i) + get(j));
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
