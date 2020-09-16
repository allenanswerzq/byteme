/* created   : 2020-08-23 20:58:09
 * accepted  : 2020-09-16 22:18:32
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  vector<int> v = {0, 1, 2, 3, 4, 5};
  //               0  0  0  1  1  1
  int n = v.size();
  int lo = -1;
  int hi = n;
  int val = 5;
  while (lo + 1 < hi) {
    int md = (lo + hi) >> 1;
    assert(0 <= md && md < n);
    if (v[md] > val) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  trace(lo, hi);
  // assert(v[hi] > val);
  // assert(v[lo] <= val);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
