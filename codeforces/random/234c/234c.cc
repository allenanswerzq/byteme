//=============================================================
// Name        : 234c
// Date        : Mon Jul  1 09:40:15 CST 2019
// Accepted    : Mon Jul  1 09:53:26 CST 2019
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
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int n;
  cin >> n;
  vector<int> pn(n + 1), pp(n + 1);
  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    pn[i + 1] = pn[i] + (x <= 0);
    pp[i + 1] = pp[i] + (x >= 0);
  }
  trace(pp, pn);
  int ans = (1 << 30);
  for (int i = 0; i < n - 1; ++i) {
    int x = pp[i + 1] - pp[0];
    int y = pn[n] - pn[i + 1];
    ans = min(ans, x + y);
  }
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
