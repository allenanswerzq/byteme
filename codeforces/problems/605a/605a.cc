/* created   : 2020-04-19 22:30:49
 * accepted  : 2020-04-19 23:28:37
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    x--;
    a[x] = i;
  }
  trace(a);
  int ans = 0;
  int lo = 0;
  while (lo < n) {
    int hi = lo + 1;
    while (hi < n && a[hi] > a[hi - 1]) {
      hi++;
    }
    ans = max(ans, hi - lo);
    trace(ans, lo, hi);
    lo = hi;
  }
  cout << n - ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
