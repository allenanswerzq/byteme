/*
 * created   : 2019-07-27 22:56:24
 * accepted  : 2019-07-27 23:06:15
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
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  for (int k = 0; k < 1000; ++k) {
    for (int j = k + 1; j < 1000; ++j) {
      for (int i = j + 1; i < 1000; ++i) {
        if (a <= i && 2 * a >= i &&
            b <= j && 2 * b >= j &&
            c <= k && 2 * c >= k &&
            d <= i && d <= j && d <= k &&
            2 * d >= k && 2 * d < i && 2 * d < j) {
          cout << i << "\n";
          cout << j << "\n";
          cout << k << "\n";
          return;
        }
      }
    }
  }
  cout << -1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
