//=============================================================
// Name        : 190a
// Date        : Fri Jun 28 18:46:38 CST 2019
// Accepted    : Fri Jun 28 18:58:28 CST 2019
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
  int n, m;
  cin >> n >> m;
  if (n == 0 && m > 0) {
    cout << "Impossible" << "\n";
    return;
  }
  int mi = max(m, n);
  int mx = max(mi, n - 1 + m);
  cout << mi << " " << mx << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
