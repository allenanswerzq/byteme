/* created   : 2020-05-22 22:08:24
 * accepted  : 2020-05-22 22:50:14
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const double EPS = 1e-6;

int sign(double x) {
  if (x < -EPS) {
    return -1;
  }
  else if (x > EPS) {
    return 1;
  }
  else {
    return 0;
  }
}

void solve() {
  int n, f; cin >> n >> f;
  vector<double> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  double lo = -1e6;
  double hi = 1e6;
  while (fabs(lo - hi) > EPS) {
    double md = (lo + hi) / 2;
    vector<double> b = a;
    vector<double> ps(n + 1);
    for (int i = 0; i < n; i++) {
      b[i] -= md;
      ps[i + 1] = ps[i] + b[i];
    }
    double mi = 1e10;
    double mx = -1e10;
    for (int i = f; i <= n; i++) {
      mi = min(mi, ps[i - f]);
      mx = max(mx, ps[i] - mi);
    }
    if (sign(mx - 0) >= 0) {
      lo = md;
    }
    else {
      hi = md;
    }
  }
  cout << (int) (1000 * hi) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
