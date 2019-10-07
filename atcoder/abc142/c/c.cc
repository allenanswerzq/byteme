/* created   : 2019-10-07 19:18:00
 * accepted  : 2019-10-07 19:19:40
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
  int n; cin >> n;
  vector<pair<int, int>> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i].x;
    v[i].y = i;
  }
  sort(v.begin(), v.end());
  trace(v);
  for (int i = 0; i < n; i++) {
    cout << v[i].y + 1 << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
