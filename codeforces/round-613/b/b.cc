/* created   : 2020-01-10 22:11:59
 * accepted  : 2020-01-10 22:41:00
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

const int N = 1e5 + 7;
int a[N];
int n;

ll go(int lo, int hi) {
  ll mx = 0;
  ll cur = 0;
  for (int i = lo; i < hi; i++) {
    cur = max(0ll, cur + a[i]);
    mx = max(mx, cur);
  }
  return mx;
}

void solve() {
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    sum += a[i];
  }
  ll mx = max(go(0, n - 1), go(1, n));
  trace(sum, mx);
  cout << ((sum > mx) ? "YES" : "NO") << '\n';
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
