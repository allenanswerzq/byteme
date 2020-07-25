/* created   : 2020-02-07 20:23:13
 * accepted  : 2020-02-07 21:29:38
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
  int n, m; cin >> n >> m;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  ll ans = 0;
  ll mx = 0;
  for (int i = 0; i < n; i++) {
    ans++;
    if (a[i] > mx) {
      mx++;
    }
  }
  ans += (a[n - 1] - mx);
  cout << accumulate(all(a), 0ll) - ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
