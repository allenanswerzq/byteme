//=============================================================
// Name        : 312a
// Date        : Sat Jun 29 15:30:45 CST 2019
// Accepted    : Sat Jun 29 16:10:20 CST 2019
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
  getline(cin, s);
  for (int i = 0; i < n; ++i) {
    getline(cin, s);
    int na = (int) s.size();
    bool a = 0, b = 0;
    if (na >= 5 && s.substr(na - 5) == "lala.") {
      a = 1;
    }
    if (na >= 5 && s.substr(0, 5) == "miao.") {
      b = 1;
    }
    if (a && !b) {
      cout << "Freda's" << "\n";
    }
    else if (!a && b) {
      cout << "Rainbow's" << "\n";
    }
    else {
      cout << "OMG>.< I don't know!" << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
