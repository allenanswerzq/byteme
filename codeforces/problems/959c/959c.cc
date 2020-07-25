/* created   : 2020-03-02 14:47:49
 * accepted  : 2020-03-02 15:14:20
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
  int n; cin >> n;
  if (n <= 5) {
    cout << -1 << '\n';
  }
  else {
    cout << 1 << ' ' << 2 << '\n';
    cout << 1 << ' ' << 3 << '\n';
    cout << 1 << ' ' << 4 << '\n';
    for (int i = 5; i <= n; i++) {
      cout << 2 << ' ' << i << '\n';
    }
  }
  for (int i = 1; i < n; i++) {
    cout << i << ' ' << i + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
