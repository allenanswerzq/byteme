/* created   : 2019-09-29 22:02:54
 * accepted  : 2019-09-29 22:07:03
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
  int sa = 0;
  int sg = 0;
  vector<bool> ans(n);
  for (int i = 0; i < n; i++) {
    int a, g; cin >> a >> g;
    if (abs(sa + a - sg) <= 500) {
      sa += a;
      ans[i] = true;
    }
    else {
      sg += g;
      ans[i] = false;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << (ans[i] ? 'A' : 'G');
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
