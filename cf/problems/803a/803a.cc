/* created   : 2020-03-14 23:02:19
 * accepted  : 2020-03-15 08:59:41
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define mt make_tuple
#define all(x) (x).begin(), (x).end()
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;
typedef pair<int, int> pii;

const int N = 120;
int a[N][N];

void solve() {
  int n, k; cin >> n >> k;
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      if (k <= 0) break;
      if (i == j) {
        a[i][j] = 1;
        k--;
        continue;
      }
      if (k >= 2 && !a[i][j] && !a[j][i]) {
        a[i][j] = 1;
        a[j][i] = 1;
        k -= 2;
      }
    }
  }
  if (k > 0) {
    cout << -1 << '\n';
    return;
  }
  for (int i = 0; i < n; i++) {
    for (int j = i; j < n; j++) {
      assert(a[i][j] == a[j][i]);
    }
  }
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      cout << a[i][j] << (j == n - 1 ? '\n' : ' ');
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
