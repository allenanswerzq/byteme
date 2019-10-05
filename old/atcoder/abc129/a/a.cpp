//=============================================================
// Name        : a
// Date        : Mon Jun 10 10:10:23 CST 2019
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
  vector<int> a(3);
  for (int i = 0; i < 3; ++i) {
    cin >> a[i];
  }
  int ans = 1e9;
  for (int i = 0; i < 3; ++i) {
    for (int j = i + 1; j < 3; ++j) {
      ans = min(ans, a[i] + a[j]);
    }
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
