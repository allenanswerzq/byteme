/* created   : 2019-08-11 19:09:20
 * accepted  : 2019-08-11 20:13:14
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
  int h1, h2;
  cin >> h1 >> h2;
  int a, b;
  cin >> a >> b;
  ll cur = h1;
  int ans = -1;
  for (int i = 0; i < 100000; i++) {
    int day = 12;
    if (i == 0) {
      day = 8;
    }
    if ((h2 - cur + a - 1) / a <= day) {
      cur = h2;
      ans = i;
      break;
    }
    cur += (ll) a * day;
    cur -= (ll) b * 12;
  }
  cout << (cur == h2 ? ans : -1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
