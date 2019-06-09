//=============================================================
// Name        : 625b
// Date        : Sat Jun  8 15:18:50 CST 2019
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
  string a, b;
  cin >> a >> b;
  int ans = 0;
  for (int i = 0; i < sz(a); ++i) {
    if (a.substr(i, sz(b)) == b) {
      ans++;
      i += sz(b) - 1;
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
