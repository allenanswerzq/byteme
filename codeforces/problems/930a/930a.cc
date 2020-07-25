/* created   : 2019-10-26 23:16:58
 * accepted  : 2019-10-26 23:36:28
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> h(n + 1);
  for (int i = 2; i <= n; i++) {
    int x; cin >> x;
    h[i] = h[x] + 1;
  }
  const int N = 1e5 + 7;
  vector<int> a(N);
  for (int i = 1; i <= n; i++) {
    a[h[i]]++;
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    ans += a[i] % 2;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
