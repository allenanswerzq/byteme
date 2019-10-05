//=============================================================
// Name        : 146b
// Date        : Wed Jul  3 21:41:16 CST 2019
// Accepted    : Wed Jul  3 21:44:50 CST 2019
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
  int a, b;
  cin >> a >> b;
  for (int i = a + 1; ; ++i) {
    string s = to_string(i);
    string t;
    for (int j = 0; j < sz(s); ++j) {
      if (s[j] == '4' || s[j] == '7') {
        t += s[j];
      }
    }
    if (t == to_string(b)) {
      cout << i << "\n";
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
