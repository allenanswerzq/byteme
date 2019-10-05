//=============================================================
// Name        : 194b
// Date        : Thu Jul  4 22:09:14 CST 2019
// Accepted    : Thu Jul  4 22:48:10 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
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
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll g = (n + 1) * 4 * n / __gcd(n + 1, 4 * n);
    cout << g / (n + 1) + 1 << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
