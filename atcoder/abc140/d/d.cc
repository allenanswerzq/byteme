/* created   : 2019-09-10 22:43:07
 * accepted  : 2019-09-10 23:10:31
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
  int n, k; cin >> n >> k;
  string s; cin >> s;
  int ans = 0;
  for (int i = 0; i + 1 < n; i++) {
    if (s[i] == 'L' && s[i + 1] == 'L') {
      ans++;
    }
  }
  for (int i = 1; i < n; i++) {
    if (s[i] == 'R' && s[i - 1] == 'R') {
      ans++;
    }
  }
  cout << min(n - 1, ans + 2 * k) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
