/* created   : 2020-02-27 22:18:08
 * accepted  : 2020-02-27 23:38:53
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

void solve() {
  int n; cin >> n;
  string a; cin >> a;
  vector<int> one(n + 1);
  vector<int> bal(n + 1);
  for (int i = 0; i < n; i++) {
    one[i + 1] = one[i] + (a[i] == '1');
    int zero = (i + 1) - one[i + 1];
    bal[i + 1] = zero - one[i + 1];
  }
  trace(bal);
  unordered_map<int, int> mp;
  for (int i = 0; i <= n; i++) {
    int x = bal[i];
    if (mp.count(x)) {
      mp[x] = min(mp[x], i);
    }
    else {
      mp[x] = i;
    }
  }
  trace(mp);
  int ans = 0;
  for (int i = 0; i <= n; i++) {
    ans = max(ans, i - mp[bal[i]]);
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
