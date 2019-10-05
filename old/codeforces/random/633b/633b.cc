//=============================================================
// Name        : 633b
// Date        : Wed Jun 26 17:35:15 CST 2019
// Accepted    : Wed Jun 26 17:43:24 CST 2019
// Author      : landcold7
// Description : Actions speak louder more than words
//=============================================================
#include <bits/stdc++.h>
using namespace std;

#define sz(x) ((int)(x).size())
#ifndef _has_trace
#define trace(...)
#endif
typedef long long ll;

void solve() {
  int n;
  cin >> n;
  // x / 5 + x / 5^2 + x / 5^3 = n
  const int maxn = 1000000;
  vector<int> ans;
  for (int i = 1; i < maxn; ++i) {
    int t = 0, x = 5;
    while (x <= i) {
      t += i / x;
      x *= 5;
    }
    if (t == n) {
      ans.push_back(i);
    }
  }
  int sa = (int) ans.size();
  cout << sa << "\n";
  for (int i = 0; i < sa; ++i) {
    cout << ans[i] << (i == sa - 1 ? "\n" : " ");
  }
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  solve();
  return 0;
}
