/* created   : 2022-02-26 21:13:21
 * accepted  : 2022-02-27 22:30:32
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  // a = a|b -> a == b
  //     00010101 a+x
  //     01111000 b
  //     01111101 b+y
  // 10^6 < 2^24
  int A, B; cin >> A >> B;
  // binary search: once we reach the mininum operations,
  // we can keep applying a = a|b to get to any number.
  auto check = [&](int md) {
    assert(A < B);
    if (B == (A | B)) return true;
    if (A + md == B) return true;
    // b + y = (a + x) | (b + y)
    // x + y + z + 1 == md
    for (int i = 0; i < md; i++) {
      // 2, 5
      // 01010 |
      // 01111 b
      // 01010
      int a = A + i;
      int b = B;
      for (int j = 20; j >= 0; j--) {
        if (a >> j & 1) {
          b |= (1 << j);
        }
        else {
          b &= ~(1 << j);
        }
      }
      // find the smallest value that a | b == b and b > B
      for (int j = 20; j >= 0; j--) {
        if ((B >> j & 1) && !(b >> j & 1))  {
          b |= (1 << j);
          if (b >= B) break;
        }
      }
      assert(b >= B);
      if (b - B <= md - 1 - i) {
        return true;
      }
    }
    return false;
  };
  int lo = 0;
  int hi = B - A + 1;
  while (lo + 1 < hi) {
    int md = lo + (hi - lo) / 2;
    trace(lo, hi, md, check(md));
    if (check(md)) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  cout << hi << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
