//=============================================================
// Name        : 946c
// Date        : Thu Jun 13 15:17:50 CST 2019
// Accepted    : Thu Jun 13 15:55:45 CST 2019
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
  string a;
  cin >> a;
  // a___ab
  // a___bc
  bool ok = 0;
  char c = 'a';
  for (int i = 0; i < sz(a); ++i) {
    if (a[i] <= c) {
      a[i] = c++;
      if (c > 'z') {
        ok = 1;
        break;
      }
    }
  }
  cout << (ok ? a : "-1") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
