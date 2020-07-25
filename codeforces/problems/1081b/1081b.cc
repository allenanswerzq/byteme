/* created   : 2020-03-09 10:47:29
 * accepted  : 2020-03-09 11:07:00
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
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a[i].x = n - x;
    a[i].y = i;
  }
  sort(all(a));
  int kind = 1;
  vector<int> ans(n);
  for (int i = 0; i < n; ) {
    int cnt = a[i].x;
    for (int j = 0; j < cnt; j++) {
      if (i + j >= n || a[i + j].x != a[i].x) {
        cout << "Impossible" << '\n';
        return;
      }
      ans[a[i + j].y] = kind;
    }
    kind++;
    i += cnt;
  }
  cout << "Possible" << '\n';
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
