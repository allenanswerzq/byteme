/* created   : 2020-02-17 13:03:07
 * accepted  : 2020-02-17 13:36:29
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  ll n, k, l; cin >> n >> k >> l;
  vector<int> a(n * k);
  int mi = 1e9 + 7;
  for (int i = 0; i < n * k; i++) {
    cin >> a[i];
    mi = min(a[i], mi);
  }
  // sort(all(a));
  vector<int> v;
  for (int i = 0; i < n * k; i++) {
    if (a[i] <= mi + l) {
      v.push_back(a[i]);
    }
  }
  sort(all(v));
  int m = v.size();
  trace(m, mi, mi + l, a, v);
  if (m < n) {
    cout << 0 << '\n';
    return;
  }
  int big = n * k - m;
  ll ans = 0;
  for (int i = m - 1; i >= 0; ) {
    if (big > k - 1) {
      ans += v[i];
      big -= k - 1;
      i--;
    }
    else {
      // i - x + 1 + big = k
      int x = i + 1 + big - k;
      big = 0;
      trace(x);
      assert(x >= 0);
      ans += v[x];
      i = x - 1;
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
