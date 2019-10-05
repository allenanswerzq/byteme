/* created   : 2019-09-25 00:25:45
 * accepted  : 2019-09-28 22:28:22
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
  int n; cin >> n;
  const int N = 1e6 + 200;
  vector<int> cnt(N);
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    cnt[x]++;
  }
  int ans = 0;
  for (int i = 0; i < N - 1; i++) {
    cnt[i + 1] += cnt[i] / 2;
    cnt[i] %= 2;
    ans += cnt[i];
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
