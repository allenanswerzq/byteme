//=============================================================
// Name        : 132a
// Date        : Thu Jul  4 23:05:26 CST 2019
// Accepted    : Thu Jul  4 23:20:12 CST 2019
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
  string s;
  getline(cin, s);
  int a = 0;
  for (int i = 0; i < sz(s); ++i) {
    int x = s[i];
    vector<int> d(8);
    for (int j = 7; j >= 0; --j) {
      d[j] = x % 2;
      x /= 2;
    }
    assert(x == 0);
    int y = 0;
    for (int j = sz(d) - 1; j >= 0; --j) {
      y = y * 2 + d[j];
    }
    int ans = (a - y + 256) % 256;
    cout << ans << "\n";
    a = y;
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
