/* created   : 2020-03-16 16:23:12
 * accepted  : 2020-03-16 16:58:48
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

double compute(ll x1, ll y1, ll x2, ll y2) {
  return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int sign(double x) {
  const double eps = 1e-9;
  if (x > eps) return 1;
  if (x < -eps) return -1;
  return 0;
}

void solve() {
  int n; cin >> n;
  double vb, vs; cin >> vb >> vs;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  trace(a);
  pii target;
  cin >> target.x >> target.y;
  double opt_time = 1e18 + 7;
  double opt_dist = 1e18 + 7;
  int ans = -1;
  for (int i = 1; i < n; i++) {
    double time = a[i] / vb;
    double dist = compute(a[i], 0, target.x, target.y);
    time += dist / vs;
    trace(time, dist, opt_time, opt_dist);
    if (sign(opt_time - time) > 0 ||
        ((sign(opt_time - time)) == 0 && (sign(opt_dist - dist) > 0))) {opt_time = time;
      opt_dist = dist;
      ans = i;
    }
  }
  cout << ans + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
