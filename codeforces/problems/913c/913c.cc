/* created   : 2020-04-18 16:29:32
 * accepted  : 2020-04-18 17:58:41
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

bool comp(pair<int, int>& a, pair<int, int>& b) {
  // a.volume / a.cost > b.volume / b.cost
  return a.x * 1ll * b.y > a.y * 1ll * b.x;
}

void solve() {
  int n, l; cin >> n >> l;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int cost; cin >> cost;
    a.push_back({1 << i, cost});
  }
  sort(all(a), comp);
  trace(a);
  ll ans = 4e18;
  ll sum = 0;
  for (int i = 0; i < n; i++) {
    ll need = l / a[i].x;
    sum += need * a[i].y;
    l -= need * a[i].x;
    // Either take one more of this type, or to use other types.
    ans = min(ans, sum + (l > 0) * a[i].y);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
