/* created   : 2020-05-17 19:01:51
 * accepted  : 2020-05-17 19:41:17
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, k; cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    a[i] = x;
  }
  int lo = 0;
  int ans = 0;
  while (lo < n) {
    if (a[lo] != k) {
      lo++;
      continue;
    }
    while (lo + 1 < n && a[lo] == a[lo + 1]) {
      lo++;
    }
    if (n - lo < k) {
      break;
    }
    bool ok = true;
    for (int i = 0; i < k; i++) {
      if (a[lo + i] != k - i) {
        ok = false;
        break;
      }
    }
    if (ok) {
      ans++;
    }
    lo++;
  }
  cout << ans << "\n";
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
