/*
 * Creat   : Sun Jul 14 12:56:28 CST 2019
 * Accept  : Sun Jul 14 13:11:40 CST 2019
 * Author  : landcold7
 */
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
  ll x, y;
  cin >> x >> y;
  if (x == 0) {
    cout << (y == 1 ? "Yes" : "No") << "\n";
    return;
  }
  else if (y == 0) {
    cout << "No" << "\n";
    return;
  }
  // 1a --> 1a, 1b
  // 1b --> 1b, 1b
  ll copy = 0;
  copy = (y - 1);
  if (copy > 0 && x >= copy && (x - copy) % 2 == 0) {
    cout << "Yes" << "\n";
    return;
  }
  cout << "No" << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
