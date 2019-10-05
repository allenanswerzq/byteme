/* Name        : a
 * Creat       : Sat Jul 13 14:52:13 CST 2019
 * Accept      : Sat Jul 13 14:53:23 CST 2019
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
  int a, b;
  cin >> a >> b;
  int ans = 0;
  if (a >= 13) {
    ans = b;
  }
  else if (6 <= a && a <= 12) {
    ans = b / 2;
  }
  else {
    ans = 0;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
