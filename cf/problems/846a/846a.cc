/* created   : 2020-03-15 15:37:34
 * accepted  : 2020-03-15 15:40:40
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = 0;
  for (int i = -1; i < n; i++) {
    int cur = 0;
    for (int j = 0; j <= i; j++) {
      cur += a[j] == 0;
    }
    for (int j = i + 1; j < n; j++) {
      cur += a[j] == 1;
    }
    ans = max(ans, cur);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
