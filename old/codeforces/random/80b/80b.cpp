//=============================================================
// Name        : 80b
// Date        : Mon Jun  3 14:02:29 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define sz(x) ((int)(x).size())

#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;
typedef vector<int> vi;

void solve() {
  int h, m;
  char c;
  cin >> h >> c >> m;
  double d = m * 1.0 / 60 * 30;
  d = (h < 12 ? h : (h - 12)) * 30 + d;
  trace(d);
  double r = m * 1.0 / 5 * 30;
  cout << d << " " << r << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
