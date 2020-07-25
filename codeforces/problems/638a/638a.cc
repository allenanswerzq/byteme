/* created   : 2020-03-15 17:25:31
 * accepted  : 2020-03-15 17:27:50
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
typedef pair<int, int> pii;

void solve() {
  ll n, a; cin >> n >> a;
  ll ans = 0;
  if (a % 2) {
    ans = (a - 1) / 2 + 1;
  }
  else {
    ans = (n - a) / 2 + 1;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
