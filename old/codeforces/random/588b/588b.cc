/*
 * Creat   : Sat Jul 13 21:37:10 CST 2019
 * Accept  : Sat Jul 13 21:41:58 CST 2019
 * Author  : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  ll n;
  cin >> n;
  vector<ll> d;
  // O(sqrt(n))
  for (ll i = 1; i * i <= n; ++i) {
    if (n % i == 0) {
      d.push_back(i);
      if (n / i != i) {
        d.push_back(n / i);
      }
    }
  }
  sort(d.begin(), d.end());
  for (int i = sz(d) - 1; i >= 0; --i) {
    bool ok = 1;
    for (ll a = 2; a * a <= d[i]; ++a) {
      if (d[i] % (a * a) == 0) {
        ok = 0;
        break;
      }
    }
    if (ok) {
      cout << d[i] << "\n";
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
