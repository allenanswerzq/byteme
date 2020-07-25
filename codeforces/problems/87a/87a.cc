/* created   : 2020-03-16 15:31:55
 * accepted  : 2020-03-16 15:40:48
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
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  ll a, b; cin >> a >> b;
  ll g = a * b / __gcd(a, b);
  ll x = g / a;
  ll y = g / b;
  if (a > b) {
    x++;
  }
  else if (a < b) {
    y++;
  }
  trace(g, x, y, a, b);
  if (x > y) {
    cout << "Dasha" << '\n';
  }
  else if (x < y) {
    cout << "Masha" << '\n';
  }
  else {
    cout << "Equal" << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
