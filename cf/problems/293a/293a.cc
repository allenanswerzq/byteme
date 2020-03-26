/* created   : 2020-03-26 23:01:13
 * accepted  : 2020-03-27 01:17:18
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#define xuyixuyi()
#define debugstream ostream
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s, t; cin >> s >> t;
  int k11, k10, k01, k00;
  k11 = k10 = k01 = k00 = 0;
  for (int i = 0; i < 2 * n; i++) {
    if (s[i] == '1' && t[i] == '1') { k11++; }
    if (s[i] == '1' && t[i] == '0') { k10++; }
    if (s[i] == '0' && t[i] == '1') { k01++; }
    if (s[i] == '0' && t[i] == '0') { k00++; }
  }
  int one = 0;
  int two = 0;
  int who = 1;
  while (1) {
    if (k11 > 0) {
      if (who & 1) one++;
      else two++;
      k11--;
    }
    else if (k10 > 0) {
      if (who & 1) one++;
      k10--;
    }
    else if (k01 > 0) {
      if ((who & 1) == 0) two++;
      k01--;
    }
    else {
      k00--;
    }
    if (k11 == 0 && k10 == 0 && k01 == 0 && k00 == 0) {
      break;
    }
    who ^= 1;
  }
  if (one > two) {
    cout << "First" << '\n';
  }
  else if (one == two) {
    cout << "Draw" << '\n';
  }
  else {
    cout << "Second" << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
