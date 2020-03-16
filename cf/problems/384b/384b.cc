/* created   : 2020-03-16 18:22:02
 * accepted  : 2020-03-16 20:13:44
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
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  cout << m * (m - 1) / 2 << '\n';
  if (k == 0) {
    for (int i = m - 1; i >= 1; i--) {
      for (int j = 1; j <= i; j++) {
        cout << j << ' ' << j + 1 << '\n';
      }
    }
  }
  else {
    for (int i = 1; i <= m - 1; i++) {
      for (int j = m; j > i; j--) {
        cout << j << ' ' << j - 1 << '\n';
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
