/* created   : 2020-02-23 19:18:18
 * accepted  : 2020-02-23 21:32:03
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
  vector<int> a(n + 1);
  int zero = n;
  cout << 1 << " ";
  for (int i = 1; i <= n; i++) {
    int x; cin >> x;
    a[x] = 1;
    while (i >= 1 && a[zero] == 1) {
      zero--;
    }
    int cnt = i - (n - zero);
    cout << cnt + 1 << (i == n ? '\n' : ' ');
    trace(i, x, cnt, zero);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
