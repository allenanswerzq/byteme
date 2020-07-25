/* created   : 2020-03-17 21:45:41
 * accepted  : 2020-03-17 22:16:38
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
  ll n, m, u, v, z, p;
  cin >> n >> m >> u >> v >> z >> p;
  u %= 4;
  v %= 2;
  z %= 4;
  trace(u, v, z);
  for (int i = 0; i < p; i++) {
    ll x, y; cin >> x >> y;
    ll w = m, h = n;
    for (int k = 0; k < u; k++) {
      swap(w, h);
      ll nx = y;
      ll ny = w - x + 1;
      x = nx;
      y = ny;
    }
    for (int k = 0; k < v; k++) {
      x = x;
      y = w - y + 1;
    }
    for (int k = 0; k < 3 * z; k++) {
      swap(w, h);
      ll nx = y;
      ll ny = w - x + ;
      x = nx;
      y = ny;
    }
    cout << x << ' ' << y << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
