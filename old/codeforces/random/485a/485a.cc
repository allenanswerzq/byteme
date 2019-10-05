/*
 * creat   : 2019-07-21 08:34:04
 * accept  : 2019-07-21 08:39:31
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
  ll a, m;
  cin >> a >> m;
  int x = 0;
  while (a % m != 0 && x < (int) 1e6) {
    a += a % m;
    x++;
  }
  cout << (a % m == 0 ? "Yes" : "No") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
