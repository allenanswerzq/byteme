/* created   : 2020-04-19 08:32:19
 * accepted  : 2020-04-19 11:18:03
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 330;
double f[N][N];

void solve() {
  int w, h, l, u, r, d;
  cin >> w >> h >> l >> u >> r >> d;
  memset(f, 0, sizeof(f));
  f[h][w] = 1.0;
  set<pair<int, int>> st;
  for (int i = u; i <= d; i++) {
    for (int j = l; j <= r; j++) {
      st.insert({i, j});
    }
  }
  for (int i = h; i >= 1; i--) {
    for (int j = w; j >= 1; j--) {
      if (st.count({i, j})) {
        f[i][j] = 0;
        continue;
      }
      if (i == h) {
        f[i][j] += f[i][j + 1];
      }
      if (j == w) {
        f[i][j] += f[i + 1][j];
      }
      if (i != h && j != w) {
        f[i][j] += f[i][j + 1] * 0.5;
        f[i][j] += f[i + 1][j] * 0.5;
      }
    }
  }
  trace(h, w, mt(f, h + 1, w + 1));
  cout << f[1][1] << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout << fixed << setprecision(10) << '\n';
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
