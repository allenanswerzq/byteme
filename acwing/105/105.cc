/* created   : 2020-05-23 09:40:37
 * accepted  : 2020-05-23 10:25:56
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  vector<int> a(n);
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt[a[i]]++;
  }
  int m; cin >> m;
  vector<pair<int, int>> v(m);
  for (int i = 0; i < m; i++) {
    cin >> v[i].x;
  }
  for (int i = 0; i < m; i++) {
    cin >> v[i].y;
  }
  int mx = 0;
  for (auto [x, y] : v) {
    mx = max(mx, cnt[x]);
  }
  int ans = 0;
  int mxx = 0;
  for (int i = 0; i < m; i++) {
    if (mx == cnt[v[i].x] && cnt[v[i].y] > mxx) {
      mxx = cnt[v[i].y];
      ans = i;
    }
  }
  cout << ans + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
