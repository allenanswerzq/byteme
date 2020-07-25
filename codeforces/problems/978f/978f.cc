/* created   : 2020-02-24 10:14:19
 * accepted  : 2020-02-24 10:44:56
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
#endif
typedef long long ll;

const int N = 2e5 + 7;
vector<int> g[N];

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<int, int>> a(n);
  vector<int> v(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i].x;
    v[i] = a[i].x;
    a[i].y = i;
  }
  for (int i = 0; i < k; i++) {
    int x, y; cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  sort(all(a));
  vector<int> ans(n);
  for (int i = 0; i < n; i++) {
    int cnt = i;
    int lo = lower_bound(all(a), make_pair(a[i].x, -1)) - a.begin();
    cnt -= (i - lo);
    for (auto t : g[a[i].y]) {
      if (v[t] < a[i].x) {
        cnt--;
      }
    }
    assert(cnt >= 0);
    ans[a[i].y] = cnt;
  }
  for (int i = 0; i < n; i++) {
    cout << ans[i] << (i == n - 1 ? '\n' : ' ');
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
