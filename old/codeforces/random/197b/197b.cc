/* created   : 2019-08-14 23:33:51
 * accepted  : 2019-08-14 23:56:18
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
  int n, m;
  cin >> n >> m;
  vector<int> a(n + 1), b(m + 1);
  for (int i = 0; i < n + 1; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < m + 1; i++) {
    cin >> b[i];
  }
  bool x = a[0] > 0;
  bool y = b[0] > 0;
  if (n == 0 && m > 0) {
    cout << 0 << "/" << 1 << "\n";
  }
  else if (n > m) {
    if (!(x ^ y)) {
      cout << "Infinity" << "\n";
    }
    else {
      cout << "-Infinity" << "\n";
    }
  }
  else if (n < m) {
    cout << 0 << "/" << 1 << "\n";
  }
  else {
    if (x ^ y) {
      cout << "-";
    }
    int g = __gcd(abs(a[0]), abs(b[0]));
    cout << abs(a[0]) / g << "/" << abs(b[0]) / g << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
