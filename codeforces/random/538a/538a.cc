/* created   : 2019-09-29 22:16:18
 * accepted  : 2019-09-29 22:33:08
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
  string s; cin >> s;
  string code = "CODEFORCES";
  int n = s.size();
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      string sub = s.substr(0, i) + s.substr(j + 1);
      if (sub == code) {
        cout << "YES" << '\n';
        return;
      }
    }
  }
  cout << "NO" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
