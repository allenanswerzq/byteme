//=============================================================
// Name        : 60a
// Date        : Fri Jul  5 23:28:59 CST 2019
// Accepted    : Fri Jul  5 23:48:18 CST 2019
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
  int n, m;
  cin >> n >> m;
  string s;
  getline(cin, s);
  int lo = 1, hi = n;
  for (int i = 0; i < m; ++i) {
    getline(cin, s);
    trace(s);
    int p = -1;
    for (int j = sz(s) - 1; j >= 0; --j) {
      if (s[j] == ' ') {
        p = j;
        break;
      }
    }
    assert(p != -1);
    int x = stoi(s.substr(p + 1));
    if ((int)s.find("left") != -1) {
      hi = min(hi, x - 1);
    }
    else {
      lo = max(lo, x + 1);
    }
    trace(lo, hi);
    if (lo > hi) {
      cout << -1 << "\n";
      return;
    }
  }
  cout << (hi - lo + 1) << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
