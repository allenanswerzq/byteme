/* created   : 2020-04-08 22:17:21
 * accepted  : 2020-04-08 23:14:17
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  string s, t; cin >> s >> t;
  vector<int> cs(26);
  int n = s.size();
  for (int i = 0; i < n; i++) {
    cs[s[i] - 'a']++;
  }
  for (int i = 0; i < t.size(); i++) {
    if (cs[t[i] - 'a'] == 0) {
      cout << -1 << '\n';
      return;
    }
  }
  const int INF = n;
  vector<vector<int>> f(n + 1, vector<int>(26, INF));
  for (int i = n - 1; i >= 0; i--) {
    for (int j = 0; j < 26; j++) {
      f[i][j] = f[i + 1][j];
    }
    f[i][s[i] - 'a'] = i;
  }
  trace(f);
  int ans = 0;
  int last = 0;
  for (int i = 0; i < t.size(); ) {
    int p = f[last][t[i] - 'a'];
    // trace(i, ans, last, p, t[i]);
    if (p == INF) {
      ans++;
      last = 0;
    }
    else {
      last = p + 1;
      i++;
    }
  }
  cout << ans + 1 << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 0; i < tc; i++) {
    solve();
  }
  return 0;
}
