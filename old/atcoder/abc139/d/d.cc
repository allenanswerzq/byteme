/* created   : 2019-09-04 00:54:58
 * accepted  : 2019-09-04 00:55:58
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
  cout << (ll) (n - 1) * (1 + n - 1) / 2 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0; }
