//=============================================================
// Name        : 112b
// Date        : Wed Jul  3 21:15:23 CST 2019
// Accepted    : Wed Jul  3 21:36:47 CST 2019
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
  int n, x, y;
  cin >> n >> x >> y;
  n /= 2;
  if ((x == n || x == n + 1) && (y == n || y == n + 1)) {
    cout << "NO" << "\n";
  }
  else {
    cout << "YES" << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
