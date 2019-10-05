/*
 * creat   : 2019-07-15 17:31:35
 * accept  : 2019-07-15 17:50:34
 * author  : landcold7
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
  string s;
  cin >> s;
  int one = 1;
  int zero = 1;
  for (auto c : s) {
    if (c == '0') {
      cout << 1 << " " << zero << "\n";
      if (++zero == 5) {
        zero = 1;
      }
    }
    else {
      cout << 3 << " " << one << "\n";
      one += 2;
      if (one == 5) {
        one = 1;
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
