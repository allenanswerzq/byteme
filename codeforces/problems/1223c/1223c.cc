/* created   : 2020-04-29 22:50:43
 * accepted  : 2020-04-29 23:14:30
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> price(n);
  for (int i = 0; i < n; i++) {
    cin >> price[i];
  }
  int x, a; cin >> x >> a;
  int y, b; cin >> y >> b;
  ll k; cin >> k;
  trace(n, x, a, y, b, price);
  vector<ll> pb(n);
  for (int i = a - 1; i < n; i += a) {
    pb[i] += x;
  }
  for (int j = b - 1; j < n; j += b) {
    pb[j] += y;
  }
  trace(pb);
  sort(all(price), greater<int>());
  int lo = 0;
  int hi = n + 1;
  while (lo + 1 < hi) {
    int md = min(n, lo + (hi - lo) / 2);
    ll ans = 0;
    vector<ll> tt(pb.begin(), pb.begin() + md);
    sort(all(tt), greater<int>());
    for (int i = 0; i < md; i++) {
      ans += tt[i] * price[i] / 100;
    }
    trace(lo, hi, md, ans, k);
    if (ans >= k) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  trace(lo, hi);
  if (hi == n + 1) {
    cout << -1 << "\n";
  }
  else {
    cout << hi << "\n";
  }
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
