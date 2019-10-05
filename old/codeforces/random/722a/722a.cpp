//=============================================================
// Name        : 722a
// Date        : Sun Jun 16 15:59:51 CST 2019
// Accepted    : Sun Jun 16 16:18:44 CST 2019
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
  string t;
  cin >> t;
  string ans;
  int cnt = (1 << 30);
  for (int i = (n == 24 ? 0 : 1); i < (n == 24 ? 24 : 13); ++i) {
    for (int j = 0; j < 60; ++j) {
      string a;
      a.resize(5);
      sprintf((char*) a.c_str(), "%02d:%02d", i, j);
      int tmp = 0;
      for (int k = 0; k < sz(a); ++k) {
        tmp += (a[k] != t[k]);
      }
      trace(a, tmp, cnt, ans);
      if (tmp < cnt) {
        cnt = tmp;
        ans = a;
      }
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
