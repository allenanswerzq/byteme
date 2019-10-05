/*
 * created   : 2019-07-31 22:19:30
 * accepted  : 2019-07-31 22:56:16
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
  int p;
  cin >> p;
  int ans = 0;
  for (int i = 1; i < p; i++) {
    bool ok = 1;
    ll x = i;
    for (int j = 0; j < p - 2; j++) {
      if (x % p == 1) {
        ok = 0;
      }
      x = (x * i) % p;
    }
    if (ok) {
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
