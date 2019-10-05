/* created   : 2019-09-01 23:29:57
 * accepted  : 2019-09-01 23:43:45
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
  int n, m; cin >> n >> m;
  vector<string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 1 << 30;
  for (int k = 2; k < 100; k++) {
    int nn = (n + k - 1) / k * k;
    int nm = (m + k - 1) / k * k;
    vector<string> b = a;
    b.resize(nn, "0");
    for (int i = 0; i < nn; i++) {
      b[i].resize(nm, '0');
    }
    int cur = 0;
    for (int i = 0; i + k <= nn; i += k) {
      for (int j = 0; j + k <= nm; j += k) {
        int ca = 0;
        int cb = 0;
        for (int w = 0; w < k; w++) {
          for (int h = 0; h < k; h++) {
            ca += (b[i + w][j + h] == '0' ? 0 : 1);
            cb += (b[i + w][j + h] == '1' ? 0 : 1);
          }
        }
        trace(k, i, j, ca, cb);
        cur += min(ca, cb);
      }
    }
    trace(k, cur, ans);
    ans = min(ans, cur);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
