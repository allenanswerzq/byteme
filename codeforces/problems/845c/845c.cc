/* created   : 2020-02-23 22:25:43
 * accepted  : 2020-02-23 22:33:36
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
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  if (n <= 2) {
    cout << "YES" << '\n';
    return;
  }
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
  }
  sort(all(a));
  vector<int> tv(2, -1);
  tv[0] = 0;
  tv[1] = 1;
  for (int i = 2; i < n; i++) {
    if (a[i].x > a[tv[0]].y) {
      tv[0] = -1;
    }
    if (a[i].x > a[tv[1]].y) {
      tv[1] = -1;
    }
    if (tv[0] == -1) {
      tv[0] = i;
    }
    else if (tv[1] == -1) {
      tv[1] = i;
    }
    else {
      cout << "NO" << '\n';
      return;
    }
  }
  cout << "YES" << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
