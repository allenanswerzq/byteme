//=============================================================
// Name        : 957a
// Date        : Fri Jun 28 11:29:38 CST 2019
// Accepted    : Fri Jun 28 15:28:26 CST 2019
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
  string s;
  cin >> s;
  bool ok = 1;
  for (auto t : {"MM", "YY", "CC"}) {
    if ((int) s.find(t) != -1) {
      ok = 0;
      break;
    }
  }
  if (!ok) {
    cout << "No" << "\n";
    return;
  }
  if ((int) s.find("?") == -1) {
    ok = 0;
  }
  else if ((int) s.find("??") == -1) {
    // Only has segment x?x
    ok = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == '?') {
        if (i == 0 || i == n - 1 || s[i - 1] == s[i + 1]) {
          ok = 1;
        }
      }
    }
  } else {
    ok = 1;
  }
  cout << (ok ? "Yes" : "No") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
