/* created   : 2020-09-06 17:08:29
 * accepted  : 2020-09-06 19:01:33
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  ll N, S; cin >> N >> S;
  // [x x + 1 ... N]
  ll lo = 0;
  ll hi = N + 1;
  while (lo + 1 < hi) {
    ll md = (lo + hi) >> 1;
    int sumd = 0;
    ll t = md;
    while (t) {
      sumd += t % 10;
      t /= 10;
    }
    if (md - sumd >= S) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  cout << N - hi + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
