/* created   : 2019-08-11 20:46:56
 * accepted  : 2019-08-11 21:03:01
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

bool check(string& s, string& a, string& b) {
  int p = s.find(a);
  if (p == -1) {
    return false;
  }
  p = s.find(b, p + (int) a.size());
  return p != -1;
}

void solve() {
  string s, a, b;
  cin >> s >> a >> b;
  bool x = check(s, a, b);
  reverse(s.begin(), s.end());
  bool y = check(s, a, b);
  string ans;
  if (x && y) {
    ans = "both";
  }
  else if (!x && y) {
    ans = "backward";
  }
  else if (x && !y) {
    ans = "forward";
  }
  else {
    ans = "fantasy";
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
