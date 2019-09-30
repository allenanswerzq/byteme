/* created   : 2019-09-10 23:18:28
 * accepted  : 2019-09-10 23:42:15
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

ll pow(int x, int p) {
  ll r = 1;
  for (int i = 0; i < p; i++) {
    r *= x;
  }
  return r;
}

void solve() {
  int a, b, c; cin >> a >> b >> c;
  int cnt = 0;
  vector<int> ans;
  for (int s = 1; s <= 81; s++) {
    ll t = b * pow(s, a) + c;
    if (0 < t && t < (int) 1e9) {
      int x = (int) t;
      vector<int> v;
      while (t) {
        v.push_back(t % 10);
        t /= 10;
      }
      if (accumulate(v.begin(), v.end(), 0) == s) {
        cnt++;
        ans.push_back(x);
      }
    }
  }
  cout << cnt << '\n';
  for (int i = 0; i < cnt; i++) {
    cout << ans[i] << (i == cnt - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
