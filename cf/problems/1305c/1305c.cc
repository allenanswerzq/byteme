/* created   : 2020-04-07 23:48:33
 * accepted  : 2020-04-08 00:20:27
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, m; cin >> n >> m;
  if (n > m) {
    cout << 0 << '\n';
    return;
  }
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll ans = 1;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      ans *= abs(a[i] - a[j]);
      ans %= m;
    }
  }
  trace(n, m, ans);
  cout << ans % m << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
