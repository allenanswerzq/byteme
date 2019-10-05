//=============================================================
// Name        : 7a
// Date        : Sat Jun 29 11:44:37 CST 2019
// Accepted    : Sat Jun 29 11:49:32 CST 2019
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
  int ans = 0;
  for (int i = 0; i < 8; ++i) {
    if ((int) a[i].find('W') == -1) {
      ans++;
    }
  }
  for (int i = 0; i < 8; ++i) {
    string col;
    for (int j = 0; j < 8; ++j) {
      col += a[j][i];
    }
    if ((int) col.find('W') == -1) {
      ans++;
    }
  }
  cout << (ans == 16 ? 8 : ans) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
