//=============================================================
// Name        : 136b
// Date        : Sun Jun  2 14:25:46 CST 2019
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
typedef vector<int> vi;

void solve() {
  int e, f;
  cin >> e >> f;
  vi a;
  while (e) {
    a.push_back(e % 3);
    e /= 3;
  }
  vi c;
  while (f) {
    c.push_back(f % 3);
    f /= 3;
  }
  trace(a, c);
  vi b;
  for (int i = 0; i < max(sz(c), sz(a)); ++i) {
    int x = i >= sz(c) ? 0 : c[i];
    int y = i >= sz(a) ? 0 : a[i];
    int t = (x - y + 3) % 3;
    b.push_back(t);
  }
  ll ret = 0;
  for (int i = sz(b) - 1; i >= 0; --i) {
    ret = ret * 3 + b[i];
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
