/*
 * created   : 2019-07-23 09:39:36
 * accepted  : 2019-07-23 17:00:45
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  string s = to_string(n);
  int ns = (int) s.size();
  int ans = ns;
  for (int i = 1; i * i <= n; ++i) {
    string x = to_string(i * i);
    int lo = 0;
    int cur = 0;
    for (int j = 0; j < ns; ++j) {
      if (s[j] == x[lo]) {
        lo++;
      }
      else {
        cur++;
      }
    }
    if (lo == (int) x.size()) {
      ans = min(ans, cur);
    }
  }
  cout << (ans == ns ? -1 : ans) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
