/*
 * creat   : 2019-07-16 06:29:54
 * accept  : 2019-07-16 06:45:13
 * author  : landcold7
 */
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
  string s;
  cin >> s;
  string ans;
  for (int i = 0; i < sz(s); ++i) {
    int na = (int) ans.size();
    if (na > 0 && s[i] == ans[na - 1]) {
      if (na >= 2 && ans[na - 2] == ans[na - 1]) {
      }
      else if (na >= 3 && ans[na - 2] == ans[na - 3]) {
      }
      else {
        ans.push_back(s[i]);
      }
    }
    else {
      ans.push_back(s[i]);
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
