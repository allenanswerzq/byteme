/* created   : 2020-04-07 23:13:37
 * accepted  : 2020-04-07 23:24:08
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int k; cin >> k;
  string s; cin >> s;
  int n = s.size();
  vector<int> ps(n + 1);
  for (int i = 0; i < n; i++) {
    ps[i + 1] = ps[i] + (s[i] == '1');
  }
  trace(ps);
  ll ans = 0;
  for (int i = 0; i <= n; i++) {
    int x = ps[i];
    int lo = lower_bound(ps.begin() + i + 1, ps.end(), x + k) - ps.begin();
    int hi = upper_bound(ps.begin() + i + 1, ps.end(), x + k) - ps.begin();
    trace(x, lo, hi);
    ans += hi - lo;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
