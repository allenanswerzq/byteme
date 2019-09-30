/* created   : 2019-09-19 23:58:22
 * accepted  : 2019-09-20 00:18:31
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
  int n, k; cin >> n >> k;
  if (k < n / 2) {
    cout << -1 << '\n';
    return;
  }
  if (n == 1) {
    cout << (k == 0 ? 1 : -1) << '\n';
    return;
  }
  vector<int> v;
  int x = k - (n - 2) / 2;
  v.push_back(x);
  v.push_back(2 * x);
  x = 2 * x + 1;
  for (int i = 3; i < n; i += 2) {
    v.push_back(x);
    v.push_back(x + 1);
    x += 2;
  }
  if (n % 2) {
    v.push_back(x);
  }
  assert((int) v.size() == n);
  for (int i = 0; i < n; i++) {
    cout << v[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
