/* created   : 2020-02-21 22:51:29
 * accepted  : 2020-02-21 23:18:57
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
  string a, b; cin >> a >> b;
  int n = b.size();
  vector<int> pr(n + 1);
  for (int i = 0; i < n; i++) {
    pr[i + 1] = pr[i] + (b[i] == '1');
  }
  auto get = [&](int l, int r) {
    return pr[r + 1] - pr[l];
  };
  ll ans = 0;
  int m = a.size();
  for (int i = 0; i < m; i++) {
    int one = get(i, n - m + i);
    int zero = n - m + 1 - one;
    assert(zero >= 0);
    ans += (a[i] == '0' ? one : zero);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
