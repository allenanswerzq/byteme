/* created   : 2020-08-23 11:29:32
 * accepted  : 2020-08-23 11:41:12
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  vector<int> b;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (i > 0) {
      b.push_back(a[i] - a[i - 1]);
    }
  }
  trace(b);
  int lo = 0;
  int ans = 0;
  n--;
  for (int hi = 0; hi < n; ) {
    trace(lo, hi);
    int val = b[hi];
    while (hi < n && b[hi] == val) {
      hi++;
    }
    // [lo...hi)
    trace(val, lo, hi);
    ans = max(ans, hi - lo);
    lo = hi;
  }
  trace(ans);
  cout << ans + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
