/* created   : 2020-08-23 12:05:27
 * accepted  : 2020-08-23 12:17:39
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> a(n);
  for (auto& it : a) {
    cin >> it.x >> it.y;
  }
  trace(n, a);
  int cnt = 1e9;
  int ans = 0;
  bool ok = false;
  for (int i = 0; i < (1 << n); i++) {
    vector<pair<int, int>> t;
    for (int j = 0; j < n; j++) {
      if (i & (1 << j)) {
        t.push_back(a[j]);
      }
    }
    trace(i, t);
    int m = t.size();
    for (int j = 0; j < m; j++) {
      t.push_back(t[j]);
    }
    vector<ll> ps(2 * m);
    for (int j = 0; j < 2 * m; j++) {
      ps[i + 1] = ps[i] + t[j].x;
    }
    bool ok = true;
    for (int j = 0; j < m; j++) {
      int nx = j + m;
      if (t[nx].y < ps[nx + 1] - ps[j]) {
        ok = false;
        break;
      }
    }
    if (ok) {
    }
  }
  cout << cnt << " " << ans << "\n";
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
