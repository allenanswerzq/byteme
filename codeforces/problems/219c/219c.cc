/* created   : 2020-05-09 00:05:44
 * accepted  : 2020-05-09 00:37:59
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 5e5 + 7;
int f[N][30];
int p[N][30];

void solve() {
  int n, k; cin >> n >> k;
  string s; cin >> s;
  for (int i = 1; i <= n; i++) {
    for (int c2 = 1; c2 <= k; c2++) {
      f[i][c2] = 1e9;
      for (int c1 = 1; c1 <= k; c1++) {
        if (c2 == c1) continue;
        int cur = f[i - 1][c1] + (c2 != s[i - 1] - 'A' + 1);
        if (cur < f[i][c2]) {
          f[i][c2] = cur;
          p[i][c2] = c1;
        }
      }
    }
  }
  int ans = 1e9;
  int col = -1;
  for (int i = 1; i <= k; i++) {
    if (ans > f[n][i]) {
      ans = f[n][i];
      col = i;
    }
  }
  trace(ans, col, mt(f[n], k + 1));
  assert(col != -1);
  string ss;
  for (int i = n; i >= 1; i--) {
    ss += (char) ('A' + col - 1);
    col = p[i][col];
  }
  cout << ans << "\n";
  reverse(all(ss));
  cout << ss << "\n";
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    cnt += ss[i] != s[i];
  }
  assert(cnt == ans);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
