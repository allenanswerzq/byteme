/* created   : 2019-08-25 13:27:57
 * accepted  : 2019-08-25 18:20:34
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
typedef pair<int, int> pii;

bool sortpii(pii& a, pii& b) {
  return (ll) a.x * b.y > (ll) a.y * b.x;
}

void solve() {
  int n, m; cin >> n >> m;
  trace(n, m);
  vector<pair<int, int>> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i].x >> v[i].y;
  }
  sort(v.begin(), v.end(), sortpii);
  vector<ll> pa(m + 1), pb(m + 1);
  for (int i = 0; i < m; i++) {
    pa[i + 1] = pa[i] + v[i].x;
  }
  for (int i = m; i > 0; i--) {
    pb[i - 1] = pb[i] + v[i - 1].y;
  }
  trace(v, pa, pb);
  for (int i = 0; i < n; i++) {
    int a, b; cin >> a >> b;
    int x = upper_bound(pa.begin(), pa.end(), a) - pa.begin();
    trace(i, a, b, x);
    if (x == m + 1) {
      if (pa[m] >= a && b == 0) {
        cout << 'Y';
      }
      else {
        cout << 'N';
      }
    }
    else {
      a -= pa[x - 1];
      double f = a * 1.0 / v[x - 1].x;
      double y = pb[x] + (1.0 - f) * v[x - 1].y;
      trace(a, f, y);
      cout << (y >= b ? 'Y' : 'N');
    }
  }
  cout << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int tc; cin >> tc;
  for (int i = 1; i <= tc; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}
