/* created   : 2020-03-13 23:23:06
 * accepted  : 2020-03-13 23:27:17
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
  int a, b, c; cin >> a >> b >> c;
  int t = b * b - 4 * a * c;
  double x = (-b + sqrt(t)) / (2 * a);
  double y = (-b - sqrt(t)) / (2 * a);
  if (x < y) {
    swap(x, y);
  }
  cout << x << '\n';
  cout << y << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(20);
  solve();
  return 0;
}
