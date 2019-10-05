//=============================================================
// Name        : 1023a
// Date        : Tue Jun 11 21:36:11 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n, m;
  cin >> n >> m;
  string s, t;
  cin >> s >> t;
  if (n > m + 1) {
    cout << "NO" << "\n";
    return;
  }
  int ix = -1;
  for (int i = 0; i < n; ++i) {
    if (s[i] == '*') {
      ix = i;
      break;
    }
  }
  if (ix == -1) {
    cout << (s == t ? "YES" : "NO") << "\n";
    return;
  }
  trace(s, t, ix);
  string pt = t.substr(0, ix) + "*" + t.substr(m - (n - ix - 1));
  cout << (s == pt ? "YES" : "NO") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
