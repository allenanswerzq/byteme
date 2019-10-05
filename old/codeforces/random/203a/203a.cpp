//=============================================================
// Name        : 203a
// Date        : Sun Jun  2 10:31:28 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;

void solve() {
  int x, t, a, b, da, db;
  cin >> x >> t >> a >> b >> da >> db;
  bool ok = 0;
  for (int i = 0; i < t && !ok; ++i) {
    for (int j = 0; j < t && !ok; ++j) {
      int c = a - da * i, d = b - db * j;
      if (c + d == x) {
        ok = 1;
      } else if (c == x) {
        ok = 1;
      } else if (d == x) {
        ok = 1;
      } else if (0 == x) {
        ok = 1;
      }
    }
  }
  cout << (ok == 1 ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
