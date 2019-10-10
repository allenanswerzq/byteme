/* created   : 2019-10-07 10:29:01
 * accepted  : 2019-10-07 12:14:57
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
    if (v[i] >= 0) {
      v[i] = -v[i] - 1;
    }
  }
  if (n % 2) {
    int mx = -1;
    int idx = -1;
    for (int i = 0; i < n; i++) {
      if (abs(v[i]) > mx) {
        mx = abs(v[i]);
        idx = i;
      }
    }
    assert(0 <= idx && idx < n);
    v[idx] = -v[idx] - 1;
  }
  for (int i = 0; i < n; i++) {
    cout << v[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
