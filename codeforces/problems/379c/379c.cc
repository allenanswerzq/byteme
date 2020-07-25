/* created   : 2020-02-07 12:14:33
 * accepted  : 2020-02-07 12:20:06
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
  vector<pair<ll, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x;
    a[i].y = i;
  }
  sort(all(a));
  trace(a);
  for (int i = 1; i < n; i++) {
    a[i].x = max(a[i].x, a[i - 1].x + 1);
  }
  vector<ll> ans(n);
  for (int i = 0; i < n; i++) {
    ans[a[i].y] = a[i].x;
  }
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
