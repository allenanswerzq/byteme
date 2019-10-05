/* created   : 2019-09-29 22:44:45
 * accepted  : 2019-09-30 01:00:51
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

int dcmp(double a, double b) {
  const double eps = 1e-9;
  if (fabs(a - b) < eps) {
    return 0;
  }
  if (eps + b < a) {
    return 1;
  }
  return -1;
}

const int N = 1200;
const double INF = 1e9 + 7;
int a[N];
int b[N];
int n;
double m;

bool check(double fuel) {
  double x = m;
  for (int i = 0; i < n; i++) {
    if (dcmp(fuel, 0) == -1) {
      return false;
    }
    // Take off from current planet.
    x = m + fuel;
    fuel -= x * 1.0 / a[i];
    if (dcmp(fuel, 0) == -1) {
      return false;
    }
    // Landing to the next planet;
    x = m + fuel;
    fuel -= x * 1.0 / b[(i + 1) % n];
    if (dcmp(fuel, 0) == -1) {
      return false;
    }
  }
  return (dcmp(fuel, 0) == -1 ? false : true);
}

void solve() {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  // trace(n, m, make_tuple(a, n), make_tuple(b, n));
  double lo = 0;
  double hi = INF;
  while (fabs(hi - lo) > 1e-6) {
    double md = lo + (hi - lo) / 2.0;
    // trace(lo, hi, md, check(md));
    if (check(md)) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  trace(lo);
  cout << (dcmp(lo, 1e9) < 1 ? lo : -1) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  solve();
  return 0;
}
