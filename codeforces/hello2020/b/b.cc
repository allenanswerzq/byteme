/* created   : 2020-01-04 20:18:09
 * accepted  : 2020-01-05 16:36:16
 * author    : landcola7
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

void solve() {
  int n; cin >> n;
  vector<pair<int, int>> a;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    vector<int> v(x);
    for (int j = 0; j < x; j++) {
      cin >> v[j];
    }
    bool ok = true;
    for (int j = 0; j < x - 1; j++) {
      ok &= v[j] >= v[j + 1];
    }
    if (ok) {
      a.emplace_back(v.back(), v[0]);
    }
  }
  sort(a.begin(), a.end());
  ll ans = (ll) n * n;
  for (int i = 0; i < a.size(); i++) {
    ans -= a.end() - lower_bound(all(a), make_pair(a[i].y, -1));
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
