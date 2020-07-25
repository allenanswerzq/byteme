/* created   : 2020-05-06 22:58:40
 * accepted  : 2020-05-06 23:13:41
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  ll l, r, x, y; cin >> l >> r >> x >> y;
  if (y % x) {
    cout << 0 << "\n";
    return;
  }
  set<pair<int, int>> st;
  int t = y / x;
  for (int i = 1; i * i <= t; i++) {
    if (t % i == 0) {
      st.insert({i, t / i});
      st.insert({t / i, i});
    }
  }
  trace(st);
  int ans = 0;
  for (auto it : st) {
    int a = it.x * x;
    int b = it.y * x;
    trace(it, a, b, l, r);
    if (l <= a && a <= r && l <= b && b <= r && __gcd(it.x, it.y) == 1) {
      ans++;
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
