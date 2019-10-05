/* created   : 2019-08-29 00:20:04
 * accepted  : 2019-08-29 00:21:01
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
  int a; string s; cin >> a >> s;
  if (a >= 3200) {
    cout << s << '\n';
  }
  else {
    cout << "red" << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
