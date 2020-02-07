/* created   : 2020-02-06 17:04:01
 * accepted  : 2020-02-06 18:30:49
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
  string a; cin >> a;
  int n = a.size();
  a = "#" + a;
  vector<int> pr(n + 1);
  for (int i = 1; i <= n; i++) {
    pr[i] = pr[i - 1] + (a[i] == 'a');
  }
  auto get_a = [&](int l, int r) {
    return pr[r] - pr[l];
  };
  auto get_b = [&](int l, int r) {
    return (r - l) - get_a(l, r);
  };
  // trace(a, pr);
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    for (int j = i; j <= n; j++) {
      ans = max(ans, get_a(0, i) + get_b(i, j) + get_a(j, n));
      // trace(ans, i, j, n, get_a(0, i), get_b(i, j), get_a(j, n));
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
