//=============================================================
// Name        : 1028b
// Date        : Sat Jun 15 13:10:19 CST 2019
// Accepted    : Sat Jun 15 13:39:16 CST 2019
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
  vector<int> a;
  int sa = 0;
  while (sa < n) {
    sa += 5;
    a.push_back(5);
  }
  int sb = 0;
  vector<int> b;
  while (sb < n) {
    sb += 4;
    b.push_back(4);
  }
  while ((int) a.size() < (int) b.size()) {
    a.push_back(5);
  }
  a.push_back(5);
  b.push_back(5);
  int na = (int) a.size();
  for (int i = 0; i < na; ++i) {
    cout << a[i] << (i == na - 1 ? "\n" : "");
  }
  int nb = (int) b.size();
  for (int i = 0; i < nb; ++i) {
    cout << b[i] << (i == nb - 1 ? "\n" : "");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
