/* created   : 2020-05-17 20:38:11
 * accepted  : 2020-05-17 21:08:45
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  vector<int> ps(n + 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ps[i + 1] = ps[i] + a[i];
  }
  trace(ps);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    int x = ps[i];
    int y = (int) sqrt(x);
    for (int k = 0; k <= y; k++) {
      int p = lower_bound(ps.begin(), ps.begin() + i - 1, x - k * k) - ps.begin();
      int u = upper_bound(ps.begin(), ps.begin() + i, x - k * k) - ps.begin();
      if (ps[p] == x - k * k) {
        // trace(i, x, k, y, ps, p);
        trace(u, p);
        ans += u - p;
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
