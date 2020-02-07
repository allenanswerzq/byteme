/* created   : 2020-02-06 16:29:04
 * accepted  : 2020-02-06 16:41:32
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  unordered_map<int, int> cnt;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    for (int j = 1; j <= 31; j++) {
      int y = (1ll << j) - x;
      if (cnt.count(y)) {
        ans += cnt[y];
      }
    }
    cnt[x]++;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
