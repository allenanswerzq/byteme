/* created   : 2019-10-09 23:39:38
 * accepted  : 2019-10-10 00:42:42
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

namespace std {
template <>
struct hash<vector<int>> {
  size_t operator()(const vector<int>& v) const {
  size_t seed = v.size();
    for (auto x : v) {
      seed ^= x + 0x9e3779b9 + (seed << 6) + (seed >> 2);
    }
    return seed;
  }
};
}

void solve() {
  int n, m; cin >> n >> m;
  unordered_map<vector<int>, int> mp;
  vector<vector<int>> a;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    vector<int> v(x);
    for (int j = 0; j < x; j++) {
      cin >> v[j];
    }
    sort(v.begin(), v.end());
    mp[v]++;
    a.push_back(v);
  }
  trace(mp);
  ll ans = 0;
  for (auto x : a) {
    int t = x.size();
    for (int mask = 0; mask < (1 << t); mask++) {
      vector<int> sub;
      for (int i = 0; i < 5; i++) {
        if (mask & (1 << i)) {
          sub.push_back(x[i]);
        }
      }
      sort(sub.begin(), sub.end());
      trace(x, sub, mp[sub]);
      if (mask == (1 << t) - 1) {
        ans += mp[sub] - 1;
      }
      else {
        ans += mp[sub];
      }
    }
  }
  trace(n, ans);
  cout << (ll) n * (n - 1) - ans << '\n';
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
