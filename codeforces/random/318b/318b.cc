//=============================================================
// Name        : 318b
// Date        : Mon Jun 24 15:53:36 CST 2019
// Accepted    : Mon Jun 24 15:57:22 CST 2019
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
  vector<int> a, b;
  for (int i = 0; i <= sz(s) - 5; ++i) {
    string sub = s.substr(i, 5);
    if (sub == "heavy") {
      a.push_back(i);
    }
    else if (sub == "metal") {
      b.push_back(i);
    }
  }
  ll ans = 0;
  for (int i = 0; i < sz(a); ++i) {
    auto ix = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
    ans += (sz(b) - ix);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
