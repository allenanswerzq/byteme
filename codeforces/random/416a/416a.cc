/*
 * created   : 2019-07-24 21:55:08
 * accepted  : 2019-07-24 22:08:13
 * author    : landcold7
 */
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define sz(x) ((int)(x).size())
#ifndef LOCAL
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  int lo = -2 * 1e9;
  int hi = 2 * 1e9;
  for (int i = 0; i < n; ++i) {
    string op;
    int x;
    char y;
    cin >> op >> x >> y;
    // trace(lo, hi, op, x, y);
    if (op == ">=") {
      if (y == 'Y') {
        lo = max(lo, x);
      }
      else {
        hi = min(hi, x - 1);
      }
    }
    else if (op == "<=") {
      if (y == 'Y') {
        hi = min(hi, x);
      }
      else {
        lo = max(lo, x + 1);
      }
    }
    else if (op == ">") {
      if (y == 'Y') {
        lo = max(lo, x + 1);
      }
      else {
        hi = min(hi, x);
      }
    }
    else if (op == "<") {
      if (y == 'Y') {
        hi = min(hi, x - 1);
      }
      else {
        lo = max(lo, x);
      }
    }
    else {
      assert(false);
    }
    trace(lo, hi);
    if (lo > hi) {
      cout << "Impossible" << "\n";
      return;
    }
  }
  cout << lo << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
