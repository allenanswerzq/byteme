//=============================================================
// Name        : 58b
// Date        : Wed Jun 19 09:45:44 CST 2019
// Accepted    : Wed Jun 19 09:52:06 CST 2019
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
  for (int i = 2; i <= n ; ++i) {
    while (n % i == 0) {
      cout << n << " ";
      n /= i;
    }
  }
  cout << 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
