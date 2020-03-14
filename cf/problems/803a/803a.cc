/* created   : 2020-03-14 23:02:19
 * accepted  : 2020-03-14 23:10:03
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
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
  for (int j = 0; j < n; j++) {
    for (int i = j + 1; i < n; i++) {
      a[i][j] = 1;
      k--;
      if (k == 0) {
        cout << -1 << '\n';
        return;
      }
      a[j][i] = 1;
      k--;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
