/* created   : 2020-02-05 10:41:41
 * accepted  : 2020-02-05 11:48:06
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
  ll n, k; cin >> n >> k;
  string a; cin >> a;
  int one = 0;
  while (a[one] == '0') {
    one++;
  }
  ll start = one;
  for (int i = one + 1; i < n; i++) {
    if (a[i] == '0' && k > 0) {
      assert(a[start] == '1');
      int p = max(start, i - k);
      if (a[p] == '1') {
        swap(a[i], a[p]);
        k -= i - p;
        start = p + 1;
      }
    }
  }
  cout << a << '\n';
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
