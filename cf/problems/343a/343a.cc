/* created   : 2020-04-18 09:46:17
 * accepted  : 2020-04-18 11:06:46
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  ll a, b; cin >> a >> b;
  ll ans = 0;
  while (b > 0) {
    ans += a / b;
    a %= b;
    swap(a, b);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
