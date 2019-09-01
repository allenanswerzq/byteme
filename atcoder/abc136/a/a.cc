/* created   : 2019-08-11 23:10:37
 * accepted  : 2019-08-11 23:11:06
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
  int a, b, c;
  cin >> a >> b >> c;
  c -= min(a - b, c);
  cout << c << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
