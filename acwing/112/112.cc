/* created   : 2020-05-27 06:27:57
 * accepted  : 2020-05-27 07:09:46
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int n, m; cin >> n >> m;
  vector<pair<int, int>> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y;
    a[i].x *= -1;
  }
  sort(all(a));
  map<int, int> cnt;
  for (int i = 0; i < m; i++) {
    int x, y; cin >> x >> y;
    cnt[x] += y;
  }
  trace(a);
  int ans = 0;
  for (auto [mi, mx] : a) {
    mi = -mi;
    auto it = cnt.upper_bound(mx);
    if (it == cnt.begin()) continue;
    if (mi <= (--it)->x) {
      trace(mi, mx, it->x);
      ans++;
      if (--cnt[it->x] == 0) {
        cnt.erase(it);
      }
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
