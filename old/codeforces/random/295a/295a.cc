/* created   : 2019-09-14 00:22:20
 * accepted  : 2019-09-14 01:18:35
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

struct node {
  int x, y, d;
};

void solve() {
  int n, m, k; cin >> n >> m >> k;
  vector<ll> v(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  }
  vector<node> op(m);
  for (int i = 0; i < m; i++) {
    int x, y, d; cin >> x >> y >> d;
    x--, y--;
    op[i] = {x, y, d};
  }
  vector<int> cnt(m + 1);
  for (int i = 0; i < k; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    // NOTE(zq7): very elegant way to handle intervals.
    cnt[x]++;
    cnt[y + 1]--;
  }
  vector<ll> dv(n + 1);
  for (int i = 0; i < m; i++) {
    cnt[i] += (i - 1 >= 0 ? cnt[i - 1] : 0);
    ll inc = (ll) op[i].d * cnt[i];
    dv[op[i].x] += inc;
    dv[op[i].y + 1] -= inc;
  }
  for (int i = 0; i < n; i++) {
    dv[i] += (i - 1 >= 0 ? dv[i - 1] : 0);
    cout << v[i] + dv[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
