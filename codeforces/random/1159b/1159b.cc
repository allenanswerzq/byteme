//=============================================================
// Name        : 1159b
// Date        : Thu Jun 27 21:53:43 CST 2019
// Accepted    : Thu Jun 27 22:11:44 CST 2019
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
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int ans = (1 << 30);
  for (int i = 0; i < n; ++i) {
    ans = min(ans, a[i] / max(i, n - 1 - i));
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
