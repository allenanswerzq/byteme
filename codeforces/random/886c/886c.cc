//=============================================================
// Name        : 886c
// Date        : Thu Jun 27 15:53:14 CST 2019
// Accepted    : Thu Jun 27 16:44:47 CST 2019
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
  vector<int> was(n + 1);
  int ans = 1;
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    if (was[x]) {
      ans++;
    }
    was[x] = 1;
  }
  trace(was);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
