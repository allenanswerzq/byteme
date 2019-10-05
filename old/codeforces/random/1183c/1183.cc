/*
 * creat   : 2019-07-18 14:45:00
 * accept  : 2019-07-18 15:05:48
 * author  : landcold7
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
  ll k, n, a, b;
  cin >> k >> n >> a >> b;
  if (k <= b) {
    cout << -1 << "\n";
    return;
  }
  if (b < k && k <= a) {
    if (n * b < k) {
      cout << 0 << "\n";
      return;
    }
    else {
      cout << -1 << "\n";
      return;
    }
  }
  assert(k > a);
  ll x = k - n * b;
  ll y = a - b;
  ll z = ceil(x * 1.0 / y) - 1;
  trace(x, y, z);
  cout << (z >= 0 ? min(z, n) : -1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    solve();
  }
  return 0;
}
