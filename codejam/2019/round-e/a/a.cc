/* created   : 2019-08-25 13:08:06
 * accepted  : 2019-08-25 13:17:18
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

struct dsu {
  int n;
  vector<int> e;

  dsu(int _n) : n(_n), e(n, -1) {
  }

  int size(int x) {
    return -e[find(x)];
  }

  int find(int x) {
    return e[x] < 0 ? x : e[x] = find(e[x]);
  }

  bool join(int a, int b) {
    a = find(a);
    b = find(b);
    if (a == b) {
      return false;
    }
    if (e[a] > e[b]) {
      swap(a, b);
    }
    e[a] += e[b];
    e[b] = a;
    n--;
    return true;
  }
};

void solve(int tc) {
  cout << "Case #" << tc << ": ";
  int n, m; cin >> n >> m;
  dsu d(n);
  int ans = 0;
  for (int i = 0; i < m; i++) {
    int x, y;
    cin >> x >> y;
    x--, y--;
    if (d.find(x) != d.find(y)) {
      d.join(x, y);
      ans++;
    }
  }
  trace(ans, d.n);
  ans += (d.n - 1) * 2;
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    solve(i);
  }
  return 0;
}
