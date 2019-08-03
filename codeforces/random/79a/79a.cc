//=============================================================
// Name        : 79a
// Date        : Thu Jul  4 12:30:46 CST 2019
// Accepted    : Thu Jul  4 13:04:54 CST 2019
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
  int x, y;
  cin >> x >> y;
  int turn = 0;
  int win = 0;
  while (1) {
    trace(x, y, turn);
    if (turn == 0) {
      if (x >= 2 && y >= 2) {
        x -= 2, y -= 2;
      }
      else if (x >= 1 && y >= 12) {
        x -= 1, y -= 12;
      }
      else if (y >= 22) {
        y -= 22;
      }
      else {
        win = 1;
        break;
      }
    }
    else {
      if (y >= 22) {
        y -= 22;
      }
      else if (x >= 1 && y >= 12) {
        x -= 1, y -= 12;
      }
      else if (x >= 2 && y >= 2) {
        x -= 2, y -= 2;
      }
      else {
        win = 0;
        break;
      }
    }
    turn ^= 1;
  }
  cout << (win ? "Hanako" : "Ciel") << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
