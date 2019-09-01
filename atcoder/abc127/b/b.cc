/* Name        : b
 * Creat       : Sat Jul 13 14:54:34 CST 2019
 * Accept      : Sat Jul 13 14:55:39 CST 2019
 * Author      : landcold7
 * Motto       : Action speaks louder more than words
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
  int r, d, x;
  cin >> r >> d >> x;
  for (int i = 0; i < 10; ++i) {
    int y = r * x - d;
    x = y;
    cout << y << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
