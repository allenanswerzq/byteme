/* created   : 2019-09-30 16:11:41
 * accepted  : 2019-09-30 16:39:49
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

void solve() {
  int n, k; cin >> n >> k;
  vector<pair<int, int>> v;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    int t = 0;
    while (x) {
      v.emplace_back(t++, x);
      x /= 2;
    }
  }
  sort(v.begin(), v.end());
  trace(v);
  const int N = 2e5 + 7;
  vector<int> cnt(N);
  vector<int> cost(N);
  int ans = (1 << 30);
  for (int i = 0; i < (int) v.size(); i++) {
    int x = v[i].y;
    cnt[x]++;
    cost[x] += v[i].x;
    if (cnt[x] >= k) {
      ans = min(ans, cost[x]);
    }
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
