/* created   : 2020-03-16 16:01:58
 * accepted  : 2020-03-16 16:15:06
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
  double a, d; cin >> a >> d;
  int n; cin >> n;
  double x, y;
  for (int i = 1; i <= n; i++) {
    ll c = floor(i * d / (4 * a));
    double l = i * d - c * 4 * a;
    if (0 <= l && l <= a) {
      x = l;
      y = 0;
    }
    else if (a < l && l <= 2 * a) {
      x = a;
      y = l - a;
      trace(x, y);
    }
    else if (2 * a < l && l <= 3 * a) {
      y = a;
      x = a - (l - 2 * a);
    }
    else {
      x = 0;
      y = a - (l - 3 * a);
    }
    cout << x << ' ' << y << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10);
  solve();
  return 0;
}
