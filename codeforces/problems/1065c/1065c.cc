/* created   : 2020-02-10 15:45:18
 * accepted  : 2020-02-10 17:08:47
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
  int n, k; cin >> n >> k;
  vector<int> a(n);
  int mi = 1e9 + 7;
  int mx = 0;
  unordered_map<ll, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mx = max(a[i], mx);
    mi = min(a[i], mi);
    cnt[a[i]]++;
  }
  int ans = 0;
  int cur = mx;
  while (cur > mi) {
    int s = 0;
    while (cur > mi) {
      s += cnt[cur];
      if (s <= k) {
        cnt[cur - 1] += cnt[cur];
        cnt.erase(cur);
        cur--;
      }
      else {
        break;
      }
    }
    ans++;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
