/* created   : 2019-08-10 10:54:04
 * accepted  : 2019-08-10 16:25:52
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int hi = n - 1;
  while (0 < hi && a[hi - 1] < a[hi]) {
    hi--;
  }
  vector<int> x = {1, 2, 3};
  cout << hi << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
