/* created   : 2020-05-03 00:04:29
 * accepted  : 2020-05-03 00:29:03
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  ll n, m, k; cin >> n >> m >> k;
  if (n > m) {
    swap(n, m);
  }
  ll x = k - n;
  ll y = m - n;
  trace(n, m, k, x, y);
  if (x < y) {
    cout << -1 << "\n";
    return;
  }
  int a = x % 2;
  int b = y % 2;
  ll ans = n;
  if (a && b) {
    ans += x - 1;
  }
  else if (!a && !b) {
    ans += x;
  }
  else if (a && !b) {
    ans += x - 2;
  }
  else {
    ans += x - 1;
  }
  trace(ans);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
