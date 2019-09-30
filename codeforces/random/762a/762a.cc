/* created   : 2019-09-08 10:03:08
 * accepted  : 2019-09-08 10:43:03
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
  ll n, k; cin >> n >> k;
  vector<ll> v;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      v.push_back(i);
      if (n / i != i) {
        v.push_back(n / i);
      }
    }
  }
  sort(v.begin(), v.end());
  trace(v);
  if ((int) v.size() < k) {
    cout << -1 << '\n';
    return;
  }
  cout << v[k - 1] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
