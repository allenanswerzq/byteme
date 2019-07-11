//=============================================================
// Name        : 612a
// Date        : Wed Jun 26 16:10:39 CST 2019
// Accepted    : Wed Jun 26 16:20:24 CST 2019
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
  int n, a, b;
  cin >> n >> a >> b;
  string s;
  cin >> s;
  vector<string> ans;
  for (int i = 0; i < 100; ++i) {
    for (int j = 0; j < 100; ++j) {
      if (i * a + b * j == n) {
        int st = 0;
        for (int k = 0; k < (i + j); ++k) {
          string sub = s.substr(st, (k < i ? a : b));
          st += (k < i ? a : b);
          ans.push_back(sub);
        }
        int sa = (int) ans.size();
        cout << sa << "\n";
        for (int k = 0; k < sa; ++k) {
          cout << ans[k] << "\n";
        }
        return;
      }
    }
  }
  cout << -1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
