/* created   : 2020-11-08 10:53:49
 * accepted  : 2020-11-08 11:04:24
 */
#include <bits/stdc++.h>
using namespace std;
#define all(x) (x).begin(), (x).end()
#define ll long long

void solve() {
  int N, T; cin >> N >> T;
  vector<int> A(N);
  for (int& a : A) cin >> a;
  ll lo = 0, hi = 1e18 + 7;
  while (lo + 1 < hi) {
    ll md = lo + (hi - lo) / 2;
    ll cnt = 0;
    for (int a : A) {
      cnt += md / a;
      if (cnt >= T) break; // in case of overflow
    }
    trace(lo, hi, cnt);
    if (cnt >= T) {
      hi = md;
    }
    else {
      lo = md;
    }
  }
  cout << hi << "\n";
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  solve();
  return 0;
}
