/* created   : 2020-05-01 20:38:42
 * accepted  : 2020-05-01 21:04:58
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

const int N = 1e6 + 7;
int a[N];

void solve() {
  int n, m; cin >> n >> m;
  auto get = [&](int i, int j) {
    assert(m * i + j < N);
    return m * i + j;
  };
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[get(i, j)];
    }
  }
  vector<int> mx(n + 1);
  for (int j = m; j >= 1; j--) {
    vector<int> col(n + 1);
    for (int i = n; i >= 1; i--) {
      col[i] = 1;
      if (a[get(i, j)] <= a[get(i + 1, j)]) {
        col[i] += col[i + 1];
      }
      mx[i] = max(mx[i], col[i]);
    }
  }
  trace(mx);
  int q; cin >> q;
  for (int i = 0; i < q; i++) {
    int x, y; cin >> x >> y;
    if (x + mx[x] - 1 >= y) {
      cout << "Yes" << "\n";
    }
    else {
      cout << "No" << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
