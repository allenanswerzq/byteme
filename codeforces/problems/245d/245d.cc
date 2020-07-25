/* created   : 2020-03-29 19:42:29
 * accepted  : 2020-03-29 20:38:44
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 120;
int a[N][N];

void solve() {
  int n; cin >>  n;
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
      if (i == j) continue;
      for (int k = 0; k < 32; k++) {
        if (a[i][j] & (1 << k)) {
          ans[i] |= (1 << k);
          ans[j] |= (1 << k);
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << ans[i] << (i == n ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
