/* created   : 2020-05-01 16:22:12
 * accepted  : 2020-05-01 18:33:01
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int sign(double x) {
  const double EPS = 1e-7;
  if (x > EPS) {
    return 1;
  }
  else if (x < -EPS) {
    return -1;
  }
  else {
    return 0;
  }
}

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  double lo = 0;
  double hi = 1e9;
  while (abs(lo - hi) > 1e-6) {
    double md = (lo + hi) / 2;
    double l = 0;
    double r = 1e9;
    for (int i = 0; i < n; i++) {
      double x = a[i] - v[i] * md;
      double y = a[i] + v[i] * md;
      l = max(l, x);
      r = min(r, y);
    }
    if (sign(l - r) <= 0) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  cout << hi << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(20);
  solve();
  return 0;
}
