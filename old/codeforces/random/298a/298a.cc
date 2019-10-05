//=============================================================
// Name        : 298a
// Date        : Thu Jun 27 19:26:44 CST 2019
// Accepted    : Thu Jun 27 19:42:37 CST 2019
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
  string s;
  cin >> s;
  int r = s.find('R');
  int l = s.find('L');
  trace(r, l);
  int x = -1, y = -1;
  if (r == -1 && l != -1) {
    int a = s.find_last_of('L');
    x = a, y = l - 1;
  }
  else if (r != -1 && l == -1) {
    int a = s.find_last_of('R');
    x = r, y = a + 1;
  }
  else if (r != -1 && l != -1) {
    x = r, y = l - 1;
  }
  else {
    assert(false);
  }
  cout << x + 1 << " " << y + 1 << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
