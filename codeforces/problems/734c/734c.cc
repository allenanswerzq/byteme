/* created   : 2020-05-10 22:23:13
 * accepted  : 2020-05-10 23:19:08
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  int x, s; cin >> x >> s;
  vector<pair<int, int>> fi(m);
  for (int i = 0; i < m; i++) {
    cin >> fi[i].y;
  }
  for (int i = 0; i < m; i++) {
    cin >> fi[i].x;
  }
  vector<pair<int, int>> se(k);
  for (int i = 0; i < k; i++) {
    cin >> se[i].y;
  }
  for (int i = 0; i < k; i++) {
    cin >> se[i].x;
  }
  const int INF = 2e9 + 7;
  ll lo = -1;
  ll hi = 4e18 + 7;
  while (lo + 1 < hi) {
    ll md = lo + (hi - lo) / 2;
    bool ok = false;
    if (n * 1ll * x <= md) {
      ok = true;
    }
    {
      // Take the first type spell only.
      for (int i = 0; i < m; i++) {
        if (s >= fi[i].x) {
          if (n * 1ll * fi[i].y <= md) {
            ok = true;
            break;
          }
        }
      }
    }
    {
      // Take the second type spell only.
      int p = upper_bound(all(se), make_pair(s, INF)) - se.begin() - 1;
      if (p >= 0) {
        int cnt = se[p].y;
        if ((max(n - cnt, 0)) * 1ll * x <= md) {
          ok = true;
        }
      }
    }
    {
      // 1. (time, money)
      // 2. (number, money)
      for (int i = 0; i < m; i++) {
        int p = upper_bound(all(se), make_pair(s - fi[i].x, INF)) - se.begin() - 1;
        if (p >= 0) {
          int time = fi[i].y;
          int cnt = se[p].y;
          if ((max(n - cnt, 0)) * 1ll * time <= md) {
            ok = true;
            break;
          }
        }
      }
    }
    if (ok) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  cout << hi << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
