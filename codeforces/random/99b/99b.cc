/* created   : 2019-08-21 00:02:21
 * accepted  : 2019-08-21 00:27:18
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

void solve() {
  int n;
  cin >> n;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x;
    a[i].y = i;
  }
  sort(a.begin(), a.end());
  if (a[0].x == a[n - 1].x) {
    cout << "Exemplary pages." << '\n';
    return;
  }
  else if ((a[0].x + a[n - 1].x) % 2 == 0) {
    int x = (a[0].x + a[n - 1].x) / 2;
    bool ok = 1;
    for (int i = 1; i < n - 1; i++) {
      if (a[i].x != x) {
        ok = 0;
      }
    }
    if (ok) {
      cout << x - a[0].x << " ml. from cup #"
           << a[0].y + 1 << " to cup #" << a[n - 1].y + 1 << ".\n";
      return;
    }
  }
  cout << "Unrecoverable configuration." << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
