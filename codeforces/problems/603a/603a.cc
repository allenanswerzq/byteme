/* created   : 2020-04-19 15:37:46
 * accepted  : 2020-04-19 19:12:16
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void amax(int& a, int b) {
  a = max(a, b);
}

const int N = 1e5 + 7;
int f[N][2][3];

void solve() {
  int n; cin >> n;
  string s; cin >> s;
  for (int i = 1; i <= n; i++) {
    for (int j = 0; j < 2; j++) {
      for (int k = 0; k < 3; k++) {
        amax(f[i][j][k], f[i - 1][j][k]);
        int equal = (s[i - 1] == ('0' + j));
        if (k + equal > 2) {
          trace(k, equal);
          continue;
        }
        amax(f[i][s[i - 1] - '0'][k + equal], f[i - 1][j][k] + 1);
      }
    }
  }
  int ans = 0;
  for (int j = 0; j < 2; j++) {
    for (int k = 0; k < 3; k++) {
      amax(ans, f[n][j][k]);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
