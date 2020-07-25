/* created   : 2019-10-13 22:07:59
 * accepted  : 2019-10-13 22:23:41
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

inline double square(double x) {
  return x * x;
}

void solve() {
  int n;
  double r;
  cin >> n >> r;
  vector<double> x(n);
  vector<double> y(n);
  for (int i = 0; i < n; i++) {
    cin >> x[i];
    double py = r;
    for (int j = 0; j < i; j++) {
      if (fabs(x[i] - x[j]) > 2 * r) {
        continue;
      }
      double dy = y[j] + sqrt(square(2 * r) - square(x[i] - x[j]));
      py = max(py, dy);
    }
    y[i] = py;
  }
  for (int i = 0; i < n; i++) {
    cout << y[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  solve();
  return 0;
}
