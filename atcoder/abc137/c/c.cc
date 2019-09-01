/* created   : 2019-08-29 11:34:01
 * accepted  : 2019-08-29 11:46:32
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
  int n; cin >> n;
  vector<vector<int>> a(n);
  for (int i = 0; i < n; i++) {
    string x; cin >> x;
    vector<int> cnt(26);
    for (int j = 0; j < (int) x.size(); j++) {
      cnt[x[j] - 'a']++;
    }
    a[i] = cnt;
  }
  map<vector<int>, int> mp;
  for (int i = 0; i < n; i++) {
    mp[a[i]]++;
  }
  ll ans = 0;
  for (auto it : mp) {
    ans += (ll) (it.y - 1) * it.y / 2;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
