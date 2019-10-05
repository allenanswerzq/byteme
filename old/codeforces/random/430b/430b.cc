/* created   : 2019-08-17 10:11:11
 * accepted  : 2019-08-17 10:32:18
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
  int n, k, x;
  cin >> n >> k >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i < n; i++) {
    vector<int> b = a;
    b.insert(b.begin() + i, x);
    int cur = 0;
    while (1) {
      bool ok = 0;
      int p = -1;
      int cnt = 0;
      for (int j = 0; j < (int) b.size(); j++) {
        int t = j;
        cnt = 0;
        while (t < (int) b.size() && b[t] == b[j]) {
          t++;
        }
        if (t - j >= 3) {
          p = j;
          ok = 1;
          cnt = t - j;
          break;
        }
        if (t - j > 0) {
          j = t - 1;
        }
      }
      if (!ok) {
        break;
      }
      else {
        trace(p, cnt, b);
        assert(p != -1);
        cur += cnt;
        b.erase(b.begin() + p, b.begin() + p + cnt);
      }
    }
    ans = max(ans, cur - 1);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
