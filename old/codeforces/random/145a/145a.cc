//=============================================================
// Name        : 145a
// Date        : Sun Jun 23 10:29:27 CST 2019
// Accepted    : Sun Jun 23 10:32:03 CST 2019
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
  string s, t;
  cin >> s >> t;
  vector<int> a, b;
  for (int i = 0; i < sz(s); ++i) {
    if (s[i] == '4' && s[i] != t[i]) {
      a.push_back(i);
    } else if (s[i] == '7' && s[i] != t[i]) {
      b.push_back(i);
    }
  }
  int mi = min(sz(a), sz(b));
  int ans = mi + (sz(a) - mi) + (sz(b) - mi);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
