/* Name        : c
 * Creat       : Fri Jul 12 18:00:02 CST 2019
 * Accept      : Fri Jul 12 18:09:41 CST 2019
 * Author      : landcold7
 * Motivation  : Action speaks louder more than words
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
  ll a, b, c, d;
  cin >> a >> b >> c >> d;
  auto go = [&](ll x) {
    ll ret = x - x / c - x / d + x / (c * d / __gcd(c, d));
    trace(x, ret, c, d);
    return max(ret, 0ll);
  };
  cout << go(b) - go(a - 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
