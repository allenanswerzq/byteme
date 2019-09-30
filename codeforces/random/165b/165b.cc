/* created   : 2019-09-15 18:01:11
 * accepted  : 2019-09-15 18:19:44
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

int n, k;

bool check(int md) {
  ll val = md;
  ll t = k;
  while (md / t) {
    val += md / t;
    t *= k;
  }
  return val >= n;
}

void solve() {
  cin >> n >> k;
  int lo = 0;
  int hi = n + 1;
  while (hi - lo > 1) {
    int md = lo + (hi - lo) / 2;
    if (check(md)) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  cout << hi << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
