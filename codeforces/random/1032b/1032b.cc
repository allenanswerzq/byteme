//=============================================================
// Name        : 1032b
// Date        : Fri Jun 28 17:04:19 CST 2019
// Accepted    : Fri Jun 28 17:19:36 CST 2019
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
  string s;
  cin >> s;
  int n = sz(s);
  trace(n);
  for (int i = 1; i <= 5; ++i) {
    int x = n / i;
    int y = n % i;
    if ((x <= 20 && y == 0) || (x <= 19)) {
      cout << i << " " << (y == 0 ? x : x + 1) << "\n";
      int p = 0, t = y;
      for (int j = 0; j < i; ++j) {
        for (int k = 0; k < x; ++k) {
          cout << s[p++];
        }
        if (t > 0) {
          cout << s[p++];
          t--;
        } else if (y) {
          cout << "*";
        }
        cout << "\n";
      }
      return;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
