/* created   : 2020-02-04 22:13:27
 * accepted  : 2020-02-05 10:32:15
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
  int n, m; cin >> n >> m;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  sort(all(a));
  vector<ll> sum(n + 1);
  vector<ll> ret(n + 1);
  ret[1] = a[1];
  sum[1] = a[1];
  for (int k = 2; k <= n; k++) {
    sum[k] = a[k];
    if (k - m >= 1) {
      sum[k] += sum[k - m];
    }
    ret[k] = ret[k - 1] + sum[k];
  }
  trace(a, ret, sum);
  for (int i = 1; i <= n; i++) {
    cout << ret[i] << (i == n ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
