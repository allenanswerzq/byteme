/* created   : 2019-08-10 23:58:52
 * accepted  : 2019-08-11 09:32:46
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
  int n, k;
  cin >> n >> k;
  // 1 2 ... n (n - 1)
  // 2 3 ... n (n - 2)
  // 3 4 ... n (n - 3)
  // n - 1 ..n 1
  int x = n * (n - 1) / 2;
  trace(k, x);
  if (k >= x) {
    cout << "no solution" << "\n";
    return;
  }
  for (int i = 0; i < n; i++) {
    cout << 0 << " " << i << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
