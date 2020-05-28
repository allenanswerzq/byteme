/* created   : 2020-05-28 00:00:00
 * accepted  : 2020-05-28 00:15:55
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long
#define square(x) (x) * (x)

int sign(double x) {
  const double EPS = 1e-6;
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
  // |------|
  //   |--|
  //    |-----|
  //       |------|
  int n, d; cin >> n >> d;
  vector<pair<double, double>> a;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    int r = square(d) - square(y);
    if (r < 0) {
      cout << -1 << "\n";
      return;
    }
    // (x - x0)
    a.push_back({x - sqrt(r), x + sqrt(r)});
  }
  sort(all(a));
  trace(a);
  double pos = -1e9;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (sign(a[i].x - pos) <= 0) {
      pos = min(pos, a[i].y);
    }
    else {
      pos = a[i].y;
      ans++;
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
