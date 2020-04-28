/* created   : 2020-04-28 22:48:36
 * accepted  : 2020-04-28 23:18:11
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n, m, k; cin >> n >> m >> k;
  map<int, int> mp;
  map<int, int> bk;
  for (int i = 0; i < n; i++) {
    int x; cin >> x;
    mp[x] = i;
    bk[i] = x;
  }
  ll ans = 0;
  for (int i = 0; i < m; i++) {
    int x; cin >> x;
    int p = mp[x];
    ans += p / k + 1;
    if (p > 0) {
      swap(mp[x], mp[bk[p - 1]]);
      swap(bk[p], bk[p - 1]);
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
