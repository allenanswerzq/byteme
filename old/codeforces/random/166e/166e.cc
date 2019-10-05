/* created   : 2019-09-03 00:13:20
 * accepted  : 2019-09-03 00:34:39
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

const int md = 1e9 + 7;

inline void add(int& a, int b) {
  if ((a += b) >= md) {
    a -= md;
  }
}

void solve() {
  int n; cin >> n;
  vector<int> dp(4);
  for (int i = 0; i < 4; i++) {
    dp[i] = (i == 0 ? 0 : 1);
  }
  vector<int> np(4);
  for (int i = 2; i <= n; i++) {
    fill(np.begin(), np.end(), 0);
    for (int j = 0; j < 4; j++) {
      for (int w = 0; w < 4; w++) {
        if (w != j) {
          add(np[j], dp[w]);
        }
      }
    }
    dp = np;
  }
  trace(dp);
  cout << dp[0] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
