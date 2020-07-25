/* created   : 2020-04-19 20:14:42
 * accepted  : 2020-04-19 21:10:47
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  ll n, p; cin >> n >> p;
  int ans = -1;
  for (int i = 1; i <= 30; i++) {
    ll x = n - p * i;
    int mi = 0;
    for (int j = 0; j < 32; j++) {
      if (x & (1 << j)) {
        mi++;
      }
    }
    if (mi <= i && i <= x) {
      ans = i;
      break;
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
