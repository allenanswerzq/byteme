/* created   : 2020-02-07 15:28:12
 * accepted  : 2020-02-07 15:56:46
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
  n *= 2;
  vector<int> a(n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (a[i]) {
      int j = i + 1;
      for (; j < n && a[j] != a[i]; j++) {
        ans += (a[j] > 0);
      }
      a[j] = 0;
      a[i] = 0;
    }
  }
  trace(a);
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
