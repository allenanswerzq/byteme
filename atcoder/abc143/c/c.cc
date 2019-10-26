/* created   : 2019-10-26 08:50:18
 * accepted  : 2019-10-26 08:52:22
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define mt make_tuple
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    int j = i;
    while (j < n && s[j] == s[i]) {
      j++;
    }
    ans++;
    i = j - 1;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
