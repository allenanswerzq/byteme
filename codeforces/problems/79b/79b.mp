/* created   : 2020-03-16 21:50:26
 * accepted  : $ACCEPTED
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
#define debugstream ostream
#endif
typedef long long ll;
typedef pair<int, int> pii;

const int N = 100;
int a[N][N];

void solve() {
  int n, m, k, t; cin >> n >> m >> k >> t;
  for (int i = 0; i < k; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    a[x][y] = -1;
  }
  int type = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (a[i][j] != -1) {
        a[i][j] = type;
        type = (type + 1) % 3;
      }
    }
  }
  for (int i = 0; i < t; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    int kind = a[x][y];
    if (kind == -1) {
      cout << "Waste" << '\n';
    }
    else if (kind == 0) {
      cout << "Carrots" << '\n';
    }
    else if (kind == 1) {
      cout << "Kiwis" << '\n';
    }
    else {
      cout << "Grapes" << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
