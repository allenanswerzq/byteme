//=============================================================
// Name        : 246b
// Date        : Fri Jun 21 14:03:51 CST 2019
// Accepted    : Fri Jun 21 14:04:42 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  ll sum = 0;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    sum += x;
  }
  cout << (sum % n == 0 ? n : n - 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
