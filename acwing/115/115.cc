/* created   : 2020-05-22 23:46:22
 * accepted  : 2020-05-23 00:01:17
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  vector<int> ans(1, 1);
  for (int k = 2; k <= N; k++) {
    int lo = -1;
    int hi = ans.size();
    while (lo + 1 < hi) {
      int md = lo + (hi - lo) / 2;
      assert(0 <= md && md < (int) ans.size());
      if (compare(ans[md], k)) {
        lo = md;
      }
      else {
        hi = md;
      }
    }
    ans.insert(ans.begin() + hi, k);
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
