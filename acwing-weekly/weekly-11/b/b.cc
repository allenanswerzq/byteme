/* created   : 2021-08-09 22:21:24
 * accepted  : 2021-08-09 22:36:42
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
using ll = long long;
using ar = array<int, 2>;

void solve() {
  int N; cin >> N;
  string s = to_string(N);
  const int INF = 1e9;
  int ans = INF;
  for (int x = 1; x * x <= N; x++) {
    string t = to_string(x * x);
    assert(t.size() <= s.size());
    int i = 0, j = 0;
    while (i < s.size() && j < t.size()) {
      if (s[i] == t[j]) {
        i++, j++;
      }
      else {
        i++;
      }
    }
    if (j == t.size()) {
      ans = min(ans, (int)(s.size() - t.size()));
    }
  }
  cout << (ans == INF ? -1 : ans) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
