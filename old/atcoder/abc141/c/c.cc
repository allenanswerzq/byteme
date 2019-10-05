/* created   : 2019-09-23 23:44:05
 * accepted  : 2019-09-24 11:45:27
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
  int n, k, q; cin >> n >> k >> q;
  vector<ll> v(n, k - q);
  for (int i = 0; i < q; i++) {
    int x; cin >> x;
    x--;
    v[x]++;
  }
  vector<vector<int>> x = {{1, 2}, {3, 4}};
  trace(n, k, q, x);
  for (int i = 0; i < n; i++) {
    if (i > 0) {
      cout << '\n';
    }
    cout << (v[i] > 0 ? "Yes" : "No");
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
