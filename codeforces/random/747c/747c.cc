/*
 * created   : 2019-08-04 22:18:45
 * accepted  : 2019-08-04 22:45:07
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
  int n, q;
  cin >> n >> q;
  vector<ll> use(n);
  for (int i = 0; i < q; i++) {
    int t, k, d;
    cin >> t >> k >> d;
    int cnt = k;
    for (int j = 0; j < n && cnt > 0; j++) {
      if (t >= use[j]) {
        cnt--;
      }
    }
    if (cnt > 0) {
      cout << -1 << "\n";
      continue;
    }
    cnt = k;
    int ans = 0;
    for (int j = 0; j < n && cnt > 0; j++) {
      if (t >= use[j]) {
        use[j] = t + d;
        ans += j + 1;
        cnt--;
      }
    }
    cout << ans << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
