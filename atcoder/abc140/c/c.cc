/* created   : 2019-09-10 00:23:17
 * accepted  : 2019-09-10 22:33:49
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
  int n; cin >> n;
  vector<int> b(n - 1), a(n);
  for (int i = 0; i < n - 1; i++) {
    cin >> b[i];
  }
  a[0] = b[0];
  a[n - 1] = b[n - 2];
  for (int i = 1; i < n - 1; i++) {
    a[i] = min(b[i], b[i - 1]);
  }
  trace(a);
  cout << accumulate(a.begin(), a.end(), 0) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
