/* created   : 2020-03-09 19:26:38
 * accepted  : 2020-03-09 19:31:35
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
#endif
typedef long long ll;

void solve() {
  ll n; cin >> n;
  ll x = 1;
  while (1) {
    if (n % x) {
      break;
    }
    x *= 3;
  }
  cout << n / x + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
