/* created   : 2020-04-18 16:13:04
 * accepted  : 2020-04-18 16:22:17
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  ll n, m; cin >> n >> m;
  if (m >= n) {
    cout << n << '\n';
    return;
  }
  ll lo = 0;
  ll hi = 2e9;
  while (lo + 1 < hi) {
    ll md = lo + (hi - lo) / 2;
    if (n - md * (md + 1) / 2 <= m) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  trace(lo, hi);
  cout << m + hi << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
