/* created   : 2020-02-17 15:29:35
 * accepted  : 2020-02-17 16:15:54
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
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  map<int, int> cnt;
  map<int, int> ccnt;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int old = cnt[a[i]];
    cnt[a[i]]++;
    if (old > 0) {
      if (--ccnt[old] == 0) {
        ccnt.erase(old);
      }
    }
    ccnt[cnt[a[i]]]++;
    trace(cnt, ccnt);
    if (ccnt.size() == 2) {
      // 3 3 3 3 1
      auto x = *ccnt.rbegin();
      auto y = *ccnt.begin();
      if (x.x - y.x == 1 && x.y == 1) {
        ans = max(ans, i + 1);
      }
      else if (y.x == 1 && y.y == 1) {
        ans = max(ans, i + 1);
      }
    }
    else if (ccnt.size() == 1) {
      auto y = *ccnt.begin();
      // 1 8
      // 100 1
      if (y.x == 1 || y.y == 1) {
        ans = max(ans, i + 1);
      }
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
