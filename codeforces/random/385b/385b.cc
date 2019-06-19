//=============================================================
// Name        : 385b
// Date        : Tue Jun 18 17:08:40 CST 2019
// Accepted    : Tue Jun 18 19:57:16 CST 2019
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
  string s;
  cin >> s;
  int n = (int) s.size();
  ll ans = 0;
  for (int i = 0; i < n - 3; ++i) {
    bool ok = 0;
    for (int j = i + 3; j < n; ++j) {
      if (s.substr(j - 3, 4) == "bear") {
        ok = 1;
      }
      if (ok) {
        ans++;
      }
    }
  }
  cout << ans << "\n";
}

void solve2() {
  string s;
  cin >> s;
  int last = -1;
  int n = (int) s.size();
  ll ans = 0;
  for (int i = 0; i < n - 3; ++i) {
    if (s.substr(i, 4) == "bear") {
      ans += (i - last) * 1ll * (n - (i + 3));
      last = i;
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
