/* created   : 2020-02-10 10:57:51
 * accepted  : 2020-02-10 12:05:56
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

unordered_map<ll, ll> mp;

ll lca(ll u, ll v, ll w = 0) {
  ll ret = 0;
  while (u != v) {
    if (u < v) {
      swap(u, v);
    }
    if (w) {
      mp[u] += w;
    }
    if (mp.count(u)) {
      ret += mp[u];
    }
    u >>= 1;
  }
  return ret;
}

void solve() {
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int t; ll u, v; cin >> t >> u >> v;
    if (t == 1) {
      ll w; cin >> w;
      lca(u, v, w);
    }
    else {
      cout << lca(u, v) << '\n';
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
