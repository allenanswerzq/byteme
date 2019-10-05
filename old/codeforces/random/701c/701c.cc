/* created   : 2019-09-11 00:13:38
 * accepted  : 2019-09-11 23:29:48
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  set<char> st;
  vector<vector<int>> pr(n + 1, vector<int>(128));
  for (int i = 0; i < n; i++) {
    st.insert(s[i]);
    for (int j = 0; j < 128; j++) {
      pr[i + 1][j] = pr[i][j];
    }
    pr[i + 1][s[i]] = pr[i][s[i]] + 1;
  }
  int all = (int) st.size();
  auto check = [&](int md) {
    for (int i = 0; i + md <= n; i++) {
      int cx = 0;
      for (int j = 0; j < 128; j++) {
        // i -- i + md - 1
        cx += ((pr[i + md][j] - pr[i][j]) > 0);
      }
      if (cx == all) {
        return true;
      }
    }
    return false;
  };
  int lo = 0;
  int hi = n + 1;
  while (hi - lo > 1) {
    int md = lo + (hi - lo) / 2;
    if (check(md)) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  trace(lo, hi);
  cout << hi << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
