/* created  : 2019-09-11 23:40:02
 * accepted : 2019-09-12 00:22:40
 * author   : landcold7
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
  ll n, m, k; cin >> n >> m >> k;
  vector<ll> a(m);
  for (int i = 0; i < m; i++) {
    cin >> a[i];
    a[i]--;
  }
  int step = 0;
  int discard = 0;
  int i = 0;
  while (i < m) {
    ll ix = a[i] - discard;
    ll nxt_pos = (ix / k + 1) * k + discard;
    while (i < m && a[i] < nxt_pos) {
      i++;
      discard++;
    }
    step++;
  }
  cout << step << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
