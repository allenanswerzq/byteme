//=============================================================
// Name        : 186b
// Date        : Tue Jun  4 10:30:36 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;

void solve() {
  int n, t1, t2, k;
  cin >> n >> t1 >> t2 >> k;
  vector<pair<double, int>> a(n);
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    double d1 = (100 - k) * 1.0 / 100 * x * t1 + y * t2;
    double d2 = (100 - k) * 1.0 / 100 * y * t1 + x * t2;
    trace(i, x, y, d1, d2);
    a[i] = {fmax(d1, d2), i + 1};
  }
  typedef pair<double, int> pdi;
  sort(a.begin(), a.end(), [](const pdi& a, const pdi& b) {
    if (fabs(a.x - b.x) <= 1e-9) {
      return a.y < b.y;
    }
    return a.x > b.x;
  });
  for (int i = 0; i < n; ++i) {
    cout << a[i].y << " " << a[i].x << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << setprecision(2) << fixed;
  solve();
  return 0;
}
