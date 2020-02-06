/* created   : 2020-02-05 22:49:18
 * accepted  : 2020-02-05 23:05:48
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
  vector<int> a(n + 2);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  a[n + 1] = 1e9 + 7;
  vector<int> fr(n + 2);
  fr[1] = 1;
  for (int i = 2; i <= n; i++) {
    fr[i] = (a[i] > a[i - 1] ? fr[i - 1] : 0) + 1;
  }
  vector<int> bk(n + 2);
  bk[n] = 1;
  for (int i = n - 1; i >= 1; i--) {
    bk[i] = (a[i] < a[i + 1] ? bk[i + 1] : 0) + 1;
  }
  trace(n, a, fr, bk);
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    ans = max(ans, fr[i] + bk[i] - 1);
    trace(i, ans);
  }
  for (int i = 1; i <= n; i++) {
    if (a[i - 1] < a[i + 1]) {
      ans = max(ans, fr[i - 1] + bk[i + 1]);
    }
    ans = max(ans, fr[i - 1]);
    ans = max(ans, bk[i + 1]);
    trace(i, ans);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
