//=============================================================
// Name        : 787a
// Date        : Thu Jun  6 16:05:15 CST 2019
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
  int a, b;
  cin >> a >> b;
  int c, d;
  cin >> c >> d;
  // b + x * a == d + k * c
  int ans = -1;
  for (int k = 0; k < 120; ++k) {
    int t = d + k * c;
    if (t >= b && (t - b) % a == 0) {
      ans = t;
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
