//=============================================================
// Name        : 870c
// Date        : Sat Jun 15 11:33:18 CST 2019
// Accepted    : Sat Jun 15 13:06:53 CST 2019
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
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    int ans = -1;
    if (x % 4 == 0) {
      ans = x / 4;
    } else if (x % 4 == 1) {
      ans = x < 9 ? -1 : 1 + (x - 9) / 4;
    } else if (x % 4 == 2) {
      ans = x < 6 ? -1 : 1 + (x - 6) / 4;
    } else {
      ans = x < 15 ? -1 : 2 + (x - 15) / 4;
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
