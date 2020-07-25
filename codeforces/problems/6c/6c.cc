/* created   : 2019-10-13 22:29:33
 * accepted  : 2019-10-13 22:57:51
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
  int n; cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  ll ta = 0;
  ll tb = 0;
  int lo = 0;
  int hi = n - 1;
  while (lo <= hi) {
    if (ta <= tb) {
      ta += v[lo++];
    }
    else {
      tb += v[hi--];
    }
  }
  cout << lo << ' ' << n - lo << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
