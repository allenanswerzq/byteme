/* created   : 2020-04-12 17:24:37
 * accepted  : 2020-04-12 21:14:26
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  int n; cin >> n;
  const ll INF = (1ll << 32);
  ll ans = 0;
  vector<ll> stk = {1};
  // (x ( x ( x x ) x ) )
  for (int i = 0; i < n; i++) {
    string x; cin >> x;
    if (x == "add") {
      ans += stk.back();
    }
    else if (x == "end") {
      stk.pop_back();
    }
    else {
      ll cnt; cin >> cnt;
      stk.push_back(min(INF, cnt * stk.back()));
    }
  }
  cout << (ans >= INF ? "OVERFLOW!!!" : to_string(ans)) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
