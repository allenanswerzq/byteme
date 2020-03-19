/* created   : 2020-03-19 00:26:00
 * accepted  : 2020-03-19 22:33:20
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
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, k; cin >> n >> k;
  if (n < 3 * k) {
    cout << -1 << '\n';
    return;
  }
  vector<int> ans(n);
  int idx = 1;
  for (int i = 0; i < 2 * k; i += 2) {
    ans[i] = idx;
    ans[i + 1] = idx++;
  }
  idx = 1;
  for (int i = 2 * k; i < 3 * k; i++) {
    ans[i] = idx++;
  }
  for (int i = 3 * k; i < n; i++) {
    ans[i] = 1;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
