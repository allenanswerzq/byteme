//============================================================================
// Name        : 817a
// Date        : Wed May 29 14:11:21 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//============================================================================
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
typedef pair<int, int> pii;

void solve() {
  ll x1, y1, x2, y2;
  cin >> x1 >> y1 >> x2 >> y2;
  ll x, y;
  cin >> x >> y;
  ll dx = abs(x1 - x2);
  ll dy = abs(y1 - y2);
  trace(dx, dy, x, y);
  bool ret = 0;
  if (dx % x == 0 && dy % y == 0) {
    if (abs(dy / y - dx / x) % 2 == 0) {
      ret = 1;
    }
  }
  cout << (ret ? "YES" : "NO") << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
