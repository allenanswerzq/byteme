/* created   : 2020-04-06 10:45:56
 * accepted  : 2020-04-06 11:15:29
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

void solve() {
  string s; cin >> s;
  vector<ll> need(3);
  for (auto& ch : s) {
    if (ch == 'B') need[0]++;
    if (ch == 'S') need[1]++;
    if (ch == 'C') need[2]++;
  }
  vector<ll> have(3);
  for (int i = 0; i < 3; i++) {
    cin >> have[i];
  }
  vector<ll> price(3);
  for (int i = 0; i < 3; i++) {
    cin >> price[i];
  }
  ll money; cin >> money;
  trace(need, have, price, money);
  auto check = [&](ll md) {
    ll tot = money;
    for (int i = 0; i < 3; i++) {
      ll x = md * need[i];
      if (have[i] - x >= 0) {
        // do nothing.
      }
      else {
        ll extra = x - have[i];
        if (tot >= extra * price[i]) {
          tot -= extra * price[i];
        }
        else {
          return false;
        }
      }
    }
    return true;
  };
  ll lo = 0;
  ll hi = 1e14 + 7;
  while (lo + 1 < hi) {
    ll md = lo + (hi - lo) / 2;
    if (check(md)) {
      lo = md;
    }
    else {
      hi = md;
    }
  }
  cout << (check(hi) ? hi : lo) << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
