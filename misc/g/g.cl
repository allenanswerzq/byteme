/* created   : 2021-10-17 10:09:47
 * accepted  : 2021-10-17 10:34:59
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

int mul(int a, int b) { return (int)((ll)a * b); }

int power(int a, ll b) {
  int res = 1;
  while (b > 0) {
    if (b & 1) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b >>= 1;
  }
  return res;
}

void solve() {
  // a ^ x = k * m + y
  // a ^ x % m = y
  // ll a, m, y; cin >> a >> m >> y;
  for (int a = 1; a < 10; a++) {
    for (int x = 1; x < 10; x++) {
      for (int m = 1; m < 10; m++) {
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int c; cin >> c;
  for (int i = 0; i < c; i++) {
    solve();
  }
  return 0;
}
