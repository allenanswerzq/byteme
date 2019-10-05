/*
 * creat   : 2019-07-16 20:14:17
 * accept  : 2019-07-16 20:26:08
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
  ll n, k;
  cin >> n >> k;
  ll t = 1;
  int p = 0;
  while (t <= n) {
    t <<= 1;
    p++;
  }
  cout << (k == 1 ? n : (1ll << p) - 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
