/* created   : 2020-02-25 23:44:49
 * accepted  : 2020-02-26 00:57:36
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

int go(ll x) {
  string s = to_string(x);
  int ans = 0;
  for (int i = 0; i < s.size(); i++) {
    ans += (s[i] - '0');
  }
  return ans;
}

void solve() {
  ll n; cin >> n;
  const ll INF = 1e18 + 7;
  ll ans = INF;
  for (int b = 1; b <= 90; b++) {
    ll t = (b * b + 4 * n);
    ll st = sqrt(t);
    if (st * st == t && st > b && (st - b) % 2 == 0) {
      ll x = (st - b) / 2;
      if (b == go(x)) {
        ans = min(ans, x);
      }
    }
  }
  cout << (ans == INF ? -1 : ans) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
