/*
 * creat   : 2019-07-16 09:26:33
 * accept  : 2019-07-16 09:38:47
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

int get(string& s, string& a) {
  int black = 0;
  int red = 0;
  int n = (int) a.size();
  for (int i = 0; i < n; ++i) {
    if (s[i] != a[i]) {
      if (s[i] == 'r') {
        red++;
      }
      else {
        black++;
      }
    }
  }
  trace(s, a, black, red);
  return max(black, red);
}

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  string a, b;
  int turn = 0;
  for (int i = 0; i < n; ++i) {
    a += (turn ? 'r' : 'b');
    turn ^= 1;
  }
  turn = 0;
  for (int i = 0; i < n; ++i) {
    b += (turn ? 'b' : 'r');
    turn ^= 1;
  }
  trace(a, b);
  int ans = get(s, a);
  ans = min(ans, get(s, b));
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
