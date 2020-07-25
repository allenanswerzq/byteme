/* created   : 2020-01-04 20:08:15
 * accepted  : 2020-01-04 20:11:07
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
  int n, m; cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  vector<string> b(m);
  for (int j = 0; j < m; j++) {
    cin >> b[j];
  }
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int x; cin >> x;
    x--;
    cout << a[x % n] + b[x % m] << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
