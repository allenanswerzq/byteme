//=============================================================
// Name        : 811b
// Date        : Tue Jun 18 14:47:33 CST 2019
// Accepted    : Tue Jun 18 14:57:06 CST 2019
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
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  for (int i = 0; i < m; ++i) {
    int l, r, x;
    cin >> l >> r >> x;
    l--, r--, x--;
    int cnt = 0;
    for (int j = l; j <= r ; ++j) {
      if (a[j] < a[x]) {
        cnt++;
      }
    }
    if (l + cnt == x) {
      cout << "Yes" << "\n";
    } else {
      cout << "No" << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
