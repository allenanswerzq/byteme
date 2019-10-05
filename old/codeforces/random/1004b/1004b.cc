/*
 * creat   : 2019-07-16 15:29:06
 * accept  : 2019-07-16 15:57:35
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
  int n, m;
  cin >> n >> m;
  string ans;
  int turn = 0;
  for (int i = 0; i < n; ++i) {
    ans += (turn == 0 ? '0' : '1');
    turn ^= 1;
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
