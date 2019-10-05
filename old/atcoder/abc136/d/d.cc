/* created   : 2019-08-11 23:31:37
 * accepted  : 2019-08-12 23:52:32
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
  string s;
  cin >> s;
  int n = s.size();
  vector<int> ans(n);
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (s[i] == 'R') {
      cnt++;
    }
    else {
      ans[i] += cnt / 2;
      ans[i - 1] += (cnt + 1) / 2;
      cnt = 0;
    }
  }
  assert(cnt == 0);
  for (int i = n - 1; i >= 0; i--) {
    if (s[i] == 'L') {
      cnt++;
    }
    else {
      ans[i] += cnt / 2;
      ans[i + 1] += (cnt + 1) / 2;
      cnt = 0;
    }
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
