//=============================================================
// Name        : 898b
// Date        : Tue Jun 11 21:27:16 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  ll n, a, b;
  cin >> n >> a >> b;
  const int maxn = 1e7 + 7;
  for (int x = 0; x < maxn; ++x) {
    if (n - a * x >= 0 && (n - a * x) % b == 0) {
      cout << "YES" << "\n";
      cout << x << " " << (n - a * x) / b << "\n";
      return;
    }
  }
  cout << "NO" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
