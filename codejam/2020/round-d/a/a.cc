/* created   : 2020-07-12 13:01:48
 * accepted  : 2020-07-12 13:09:12
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n; cin >> n;
  vector<int> a(n + 2);
  vector<int> ps(n + 2);
  a[0] = -1;
  a[n + 1] = -1;
  ps[0] = -1;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    ps[i] = max(ps[i - 1], a[i]);
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i] > ps[i - 1] && a[i] > a[i + 1]) {
      ans++;
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
