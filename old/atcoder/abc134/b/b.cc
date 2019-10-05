/*
 * created   : 2019-07-24 23:33:09
 * accepted  : 2019-07-24 23:35:20
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
  int n, d;
  cin >> n >> d;
  int ans = (n + 2 * d) / (2 * d + 1);
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
