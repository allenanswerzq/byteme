//=============================================================
// Name        : 690d1
// Date        : Sun Jul  7 16:46:48 CST 2019
// Accepted    : Sun Jul  7 17:03:21 CST 2019
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
  int r, c;
  cin >> r >> c;
  vector<string> a(r);
  for (int i = 0; i < r; ++i) {
    cin >> a[i];
  }
  vector<bool> col(c);
  for (int i = 0; i < r; ++i) {
    for (int j = 0; j < c; ++j) {
      if (a[i][j] == 'B') {
        col[j] = 1;
      }
    }
  }
  trace(col);
  int ans = 0;
  for (int i = 0; i < c; ++i) {
    if (col[i]) {
      ans++;
      while (col[i]) {
        i++;
      }
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
