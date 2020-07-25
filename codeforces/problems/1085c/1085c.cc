/* created   : 2020-05-05 22:26:18
 * accepted  : 2020-05-05 23:08:48
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

int dist(int xl, int yl, int xr, int yr) {
  return abs(xl - xr) + abs(yl - yr);
}

void go(int xl, int yl, int xr, int yr) {
  while (xl < xr) {
    cout << ++xl << " " << yl << "\n";
  }
  while (xl > xr) {
    cout << --xl << " " << yl << "\n";
  }
  while (yl > yr) {
    cout << xl << " " << --yl << "\n";
  }
  while (yl < yr) {
    cout << xl << " " << ++yl << "\n";
  }
}

void solve() {
  vector<pair<int, int>> a(3);
  for (int i = 0; i < 3; i++) {
    cin >> a[i].x >> a[i].y;
  }
  int n = 1000;
  int mx = 1e9;
  pair<int, int> best;
  for (int i = 0; i <= n; i++) {
    for (int j = 0; j <= n; j++) {
      int cur = 0;
      for (int k = 0; k < 3; k++) {
        cur += dist(i, j, a[k].x, a[k].y);
      }
      if (mx > cur) {
        mx = cur;
        best = {i, j};
      }
    }
  }
  cout << mx + 1 << "\n";
  cout << best.x << " " << best.y << "\n";
  for (int k = 0; k < 3; k++) {
    go(best.x, best.y, a[k].x, a[k].y);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
