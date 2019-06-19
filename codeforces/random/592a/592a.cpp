//=============================================================
// Name        : 592a
// Date        : Mon Jun 17 10:35:46 CST 2019
// Accepted    : Mon Jun 17 10:45:26 CST 2019
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
  vector<string> a(8);
  for (int i = 0; i < 8; ++i) {
    cin >> a[i];
  }
  int da = (1 << 30);
  int db = (1 << 30);
  for (int i = 0; i < 8; ++i) {
    for (int j = 0; j < 8; ++j) {
      bool up = 1;
      for (int k = 0; k < i; ++k) {
        if (a[k][j] != '.') {
          up = 0;
          break;
        }
      }
      bool dn = 1;
      for (int k = i + 1; k < 8; ++k) {
        if (a[k][j] != '.') {
          dn = 0;
          break;
        }
      }
      if (a[i][j] == 'W' && up) {
        da = min(da, i);
      } else if (a[i][j] == 'B' && dn) {
        db = min(db, 8 - i - 1);
      }
    }
  }
  trace(da, db);
  cout << (da <= db ? "A" : "B") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
