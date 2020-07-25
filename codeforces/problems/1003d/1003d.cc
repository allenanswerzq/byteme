/* created   : 2020-05-05 10:21:10
 * accepted  : 2020-05-05 11:06:13
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, q; cin >> n >> q;
  map<int, int> mp;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    mp[x]++;
  }
  trace(mp);
  for (int i = 0; i < q; i++) {
    int x; cin >> x;
    int ans = 0;
    for (int k = 31; k >= 0; k--) {
      int y = (1 << k);
      if (mp.count(y)) {
        int cur = min(x / y, mp[y]);
        ans += cur;
        x -= cur * y;
      }
    }
    trace(x, ans);
    cout << (x > 0 ? -1 : ans) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
