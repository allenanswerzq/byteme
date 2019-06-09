//=============================================================
// Name        : 621b
// Date        : Fri Jun  7 08:01:55 CST 2019
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
  unordered_map<int, int> m1;
  unordered_map<int, int> m2;
  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    m1[x + y]++;
    m2[x - y]++;
  }
  ll ans = 0;
  for (auto t : m1) {
    ans += t.y * (t.y - 1) / 2;
  }
  for (auto t : m2) {
    ans += t.y * (t.y - 1) / 2;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
