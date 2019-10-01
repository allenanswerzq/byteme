/* created   : 2019-09-29 23:21:07
 * accepted  : 2019-09-29 23:21:55
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
  // a equals b
    return 0;
  }
  if (b + eps < a) {
  // a greater than b
    return 1;
  }
  // a smaller than b
  return -1;
}

bool dcheck(double a, double b) {
  const double prec = 1e-6;
  double err = fabs(a - b) / max(1.0, fabs(b));
  return (dcmp(err, prec) < 1);
}

void test() {
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  test();
  return 0;
}
