/* created   : 2019-08-10 21:10:16
 * accepted  : 2019-08-10 21:13:34
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  ll ans = 0;
  for (int i = 0; i < n; ) {
    int j = i;
    while (j < n && a[j] == a[i]) {
      j++;
    }
    int x = j - i;
    ans += (ll) x * (x + 1) / 2;
    i = j;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
