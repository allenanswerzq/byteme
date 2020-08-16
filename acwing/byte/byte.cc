/* created   : 2020-06-07 18:05:58
 * accepted  : 2020-08-14 12:40:01
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  // 0000000---1111111
  //       lo--hi
  vector<int> v{0, 0, 0, 1, 1, 1, 1};
  int lo = -1;
  int hi = 7;
  while (lo + 1 < hi) {
    int md = lo + (hi - lo) / 2;
    if (v[md] == 1) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  trace(lo, hi);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
